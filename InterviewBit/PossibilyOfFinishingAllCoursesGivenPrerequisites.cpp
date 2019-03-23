bool dfsCycle(vector<int> adj[], int v, vector<bool> &onPath, vector<bool> &visited) {
    if(visited[v])
        return false;
    visited[v] = onPath[v] = true;
    for(auto i : adj[v]) {
        if((!visited[i] && dfsCycle(adj, i, onPath, 
            visited)) || onPath[i])
                return true;
    }
    return onPath[v] = false;
}

int Solution::solve(int N, vector<int> &B, vector<int> &C) {
    vector<int> adj[N];
    for(int i=0; i<B.size(); i++) {
        adj[B[i] - 1].push_back(C[i] - 1);
    }
    vector<bool> onPath(N, false);
    vector<bool> visited(N, false);
    for(int i=0; i<N; i++) {
        if(dfsCycle(adj, i, onPath, visited))
            return false;
    }
    return true;
}

