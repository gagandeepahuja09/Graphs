bool dfs(int i, vector<vector<int>>& adj, vector<bool>& vis, 
vector<bool>& pathVis) {
    if(pathVis[i])
        return false;
    if(vis[i])
        return true;
    vis[i] = pathVis[i] = true;    
    bool ans = true;    
    for(int j = 0; j < adj[i].size(); j++) {
        ans &= dfs(adj[i][j], adj, vis, pathVis);
    }
    pathVis[i] = false;
    return ans;
}

int Solution::solve(int A, vector<int> &B, vector<int> &C) {
    vector<vector<int>> adj(A + 1);
    for(int i = 0; i < B.size(); i++) {
        adj[B[i]].push_back(C[i]);
    }
    vector<bool> vis(A + 1, false);
    vector<bool> pathVis(A + 1, false);
    bool ans = true;
    
    for(int i = 0; i < B.size(); i++) {
        if(!vis[B[i]]) {
            ans = ans & dfs(B[i], adj, vis, pathVis);
        }
    }
    return ans;
}

