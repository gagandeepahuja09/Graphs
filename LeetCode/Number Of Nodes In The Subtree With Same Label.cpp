class Solution {
public:
    vector<int> ret;
    vector<vector<int>> adj;
    
    
    vector<int> dfs(string& labels, int u = 0, int p = -1) {
        vector<int> temp(26, 0);
        temp[labels[u] - 'a']++;
        for(int v : adj[u]) {
            if(v == p)  continue;
            vector<int> curr = dfs(labels, v, u);
            for(int i = 0; i < 26; i++) {
                temp[i] += curr[i];
            }
        }
        ret[u] = temp[labels[u] - 'a'];
        return temp;
    }
    
    vector<int> countSubTrees(int n, vector<vector<int>>& edges, string labels) {
        adj.clear(); adj.resize(n); ret.resize(n);
        for(int i = 0; i < edges.size(); i++) {
            int u = edges[i][0], v = edges[i][1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        dfs(labels);
        return ret;
    }
};
