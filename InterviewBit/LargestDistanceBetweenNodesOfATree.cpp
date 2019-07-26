int n;

pair<int, int> bfs(int i, vector<vector<int>>& adj) {
    int dist[n];
    memset(dist, -1, sizeof dist);
    queue<int> q;
    q.push(i);
    dist[i] = 0;
    while(!q.empty()) {
        int t = q.front();
        q.pop();
        for(auto it = adj[t].begin(); it != adj[t].end(); it++) {
            int v = *it;
            if(dist[v] == -1) {
                q.push(v);
                dist[v] = dist[t] + 1;
            }
        }
    }
    int node = 0, maxDist = 0;
    for(int j = 0; j < n; j++) {
        if(dist[j] > maxDist) {
            maxDist = dist[j];
            node = j;
        }
    }
    return { node, maxDist };
}

int Solution::solve(vector<int> &A) {
    n = A.size();
    vector<vector<int>> adj(n + 1);
    for(int i = 0; i < A.size(); i++) {
        if(A[i] == -1)
            continue;
        adj[i].push_back(A[i]);
        adj[A[i]].push_back(i);
    }
    if(!adj[0].size())
        return 0;
    pair<int, int> t1 = bfs(0, adj);
    return bfs(t1.first, adj).second;
}

