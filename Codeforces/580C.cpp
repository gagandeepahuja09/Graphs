#include<bits/stdc++.h>
using namespace std;

#define MAX 100005

int mark[MAX];
bool vis[MAX];
vector<int> adj[MAX];

int n, m, ans;

void dfs(int u, int curr) {
    if(vis[u])
        return;
    vis[u] = 1;    
    int prev = curr;
    if(mark[u])
        prev++;
    else
        prev = 0;
    if(prev > m)
        return;
    bool flag = true;
    for(auto v : adj[u]) {
        if(!vis[v]) {
            flag = false;
            dfs(v, prev);
            // vis[v] = 1; 
        }
    }   
    if(flag) {
        ans++;
    }
}

int main() {
    ans = 0;
    cin >> n >> m;
    memset(vis, 0, sizeof vis);
    for(int i = 1; i <= n; i++) {
        cin >> mark[i];
    }
    for(int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    // vis[1] = 1;
    dfs(1, 0);
    cout << ans << endl;
    return 0;
}
