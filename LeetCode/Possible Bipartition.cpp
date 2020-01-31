class Solution {
public:
    int dfs(int u, vector<int>& color, vector<vector<int>>& adj, int c) {
        if(color[u] == -c)
            return false;
        if(color[u] == c)
            return true;
        color[u] = c;
        for(int i = 0; i < adj[u].size(); i++) {
            int v = adj[u][i];
            if(!dfs(v, color, adj, -c)) {
                return false;
            }
        }
        return true;
    }
    
    bool possibleBipartition(int n, vector<vector<int>>& d) {
        vector<vector<int>> adj(n + 1);
        for(int i = 0; i < d.size(); i++) {
            adj[d[i][0]].push_back(d[i][1]);
            adj[d[i][1]].push_back(d[i][0]);
        }
        vector<int> color(n + 1, 0);
        for(int i = 1; i <= n; i++) {
            if(color[i] == 0 && !dfs(i, color, adj, 1))
                return false;
        }
        return true;
    }
};
