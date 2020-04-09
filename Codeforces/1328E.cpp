#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> g;
int t;
vector<int> tIn, tOut, d, par;

void dfs(int u, int depth = 0, int p = -1) {
    tIn[u] = t++;
    d[u] = depth;
    par[u] = p;
    for(auto v : g[u]) {
        if(v == p)
            continue;
        dfs(v, depth + 1, u);
    }
    tOut[u] = t++;
}

bool isAnc(int p, int u) {
    return (tIn[p] <= tIn[u] && tOut[p] >= tOut[u]);
}

int main() {
    int n, m;
    cin >> n >> m;
    t = 0;
    g.resize(n); tIn.resize(n); tOut.resize(n);
    d.resize(n); par.resize(n);
    for(int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        u--; v--;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    dfs(0);
    while(m--) {
        int k;
        cin >> k;
        vector<int> v;
        int maxDepth = 0, u = 0;
        for(int i = 0; i < k; i++) {
            int x; cin >> x; x--;
            v.push_back(x);
            if(d[x] > maxDepth) {
                maxDepth = d[x];
                u = x;
            }
        }
        bool ok = true;
        for(auto i : v) {
            if(i != 0)
                ok &= isAnc(par[i], u);
        }
        cout << (ok ? "YES" : "NO") << endl;
    }
}
