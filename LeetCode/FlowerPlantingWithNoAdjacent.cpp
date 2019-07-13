class Solution {
public:
    bool used(vector<vector<int>>& adj, int i, int flower, vector<int>& ret) {
        for(auto& neigh: adj[i]) {
            if(ret[neigh - 1] == flower)
                return true;
        }
        return false;
    }
    
    void dfs(vector<vector<int>>& adj, int i, vector<int>& ret) {
        if(ret[i - 1] != -1)
            return;
        int f = 1;
        while(used(adj, i, f, ret)) {
            f++;
        }
        ret[i - 1] = f;
        for(auto& x : adj[i]) {
            dfs(adj, x, ret);
        }
    }
    
    
    vector<int> gardenNoAdj(int N, vector<vector<int>>& paths) {
        int flower = 1;
        vector<vector<int>> adj(N + 1);
        for(int i = 0; i < paths.size(); i++) {
            adj[paths[i][0]].push_back(paths[i][1]);
            adj[paths[i][1]].push_back(paths[i][0]);
        }
        vector<int> ret(N, -1);
        for(int i = 1; i <= N; i++) {
            if(ret[i - 1] == -1) {
                dfs(adj, i, ret);
            }
        }
        return ret;
    }
};
