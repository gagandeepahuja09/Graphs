#include<bits/stdc++.h>
using namespace std;

#define ll long long int
#define MAX 100005

bool vis[MAX];
vector<ll> adj[MAX];

ll n, m, cnt = 0, ans, k;

void dfs(int u) {
    if(vis[u])
        return;
    vis[u] = 1;
    cnt++;
    for(auto v : adj[u]) {
        dfs(v);
    }
}

int main() {
    ans = 0;
    cin >> n >> m >> k;
    vector<ll> c(k);
    for(int i = 0; i < k; i++)
        cin >> c[i];
    memset(vis, 0, sizeof vis);
    for(int i = 1; i <= m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<ll> comp;
    for(int i = 0; i < k; i++) {
        cnt = 0;
        dfs(c[i]);
        comp.push_back(cnt);
        // cout << cnt << endl;
    }
    sort(comp.begin(), comp.end());
    cnt = 0;
    for(int i = 1; i <= n; i++) {
        if(!vis[i]) {
            dfs(i);
        }
    }
    // cout << cnt << endl;
    comp.back() += cnt;
    ll req = 0;
    for(int i = 0; i < comp.size(); i++) {
        req += (ll)((comp[i] * (comp[i] - 1)) / 2);
    }
    // cout << req << " ";
    cout << req - m << endl;
    return 0;
}
