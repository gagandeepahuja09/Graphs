/*
Check whether the graph is bipartite or not

Given a undirected graph having A nodes. A matrix B of size M x 2 is given which represents the edges such that there is an edge between B[i][0] and B[i][1].

Find whether the given graph is bipartide or not.
*/

bool dfs(int i, vector<int>& color, vector<bool>& vis, vector<vector<int>>& adj) {
    if(vis[i])
        return 1;
    vis[i] = true;    
    if(color[i] == 0)
        color[i] = 1;
    int ans = false;    
    for(int j = 0; j < adj[i].size(); j++) {
        if(color[i] == color[adj[i][j]]) {
                return false;
            }
        if(!vis[adj[i][j]]) {
            if(color[i] == 1)
                color[adj[i][j]] = 2;
            if(color[i] == 2)
                color[adj[i][j]] = 1;
            if(!dfs(adj[i][j], color, vis, adj)) 
                return false;
        }
    }
    return true;
}

int Solution::solve(int A, vector<vector<int> > &B) {
    set<int> s1, s2;
    vector<vector<int>> adj(A);
    for(int i = 0; i < B.size(); i++) {
        adj[B[i][0]].push_back(B[i][1]);
        adj[B[i][1]].push_back(B[i][0]);
    }
    vector<int> color(A, 0);
    vector<bool> vis(A, false);
    for(int i = 0; i < A; i++) {
        if(!dfs(i, color, vis, adj))
            return 0;
    }
    return 1;
}

