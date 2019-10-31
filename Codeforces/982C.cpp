#include<bits/stdc++.h>
using namespace std;

#define MAX 100005

int sz[MAX];
bool vis[MAX];
vector<int> adj[MAX];

int n, m, ans;

int dfs(int u, int parent) {
    sz[u] = 1;
    for(auto v : adj[u]) {
        if(v != parent) {
            dfs(v, u);
            sz[u] += sz[v];
        }
        if(sz[v] % 2 == 0) {
            ans++;
        }
    }
}

int main() {
    ans = 0;
    cin >> n;
    memset(sz, 0, sizeof sz);
    for(int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs(1, 0);
    cout << ((n % 2) ? -1 : ans) << endl;
    return 0;
}
