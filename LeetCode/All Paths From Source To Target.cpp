class Solution {
public:
    vector<vector<int>> ret;
    void dfs(vector<vector<int>>& g, vector<bool>& vis, vector<int>& path, int i) {
        if(vis[i])
            return;
        if(i == g.size() - 1) {
            path.push_back(i);
            ret.push_back(path);
            path.pop_back();
        }
        vis[i] = true;
        path.push_back(i);
        for(int j = 0; j < g[i].size(); j++) {
            dfs(g, vis, path, g[i][j]);
        }
        vis[i] = false;
        path.pop_back();
    }
    
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<bool> vis(n, false);
        vector<int> path;
        dfs(graph, vis, path, 0);
        return ret;
    }
};
