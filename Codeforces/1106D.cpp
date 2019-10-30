#include<bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> g(n + 1);
    for(int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    vector<bool> vis(n + 1, false);
    priority_queue<int, vector<int>, greater<int>> pq;
    pq.push(1);
    while(!pq.empty()) {
        int t = pq.top();
        pq.pop();
        if(vis[t])
            continue;
        vis[t] = 1;    
        cout << t << " ";
        for(auto x : g[t]) {
            pq.push(x);
        }
    }
    return 0;
}
