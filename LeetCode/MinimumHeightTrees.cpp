class Solution {
public:
    int mn;
    
    void dfs(int i, vector<vector<int>>& adj, vector<bool>& vis, int cnt) {
        int c = 0;
        if(vis[i])
            return;
        vis[i] = true;
        for(int j = 0; j < adj[i].size(); j++) {
            if(vis[adj[i][j]])
                c++;
            else
                dfs(adj[i][j], adj, vis, cnt + 1);
        }
        if(c == adj[i].size()) {
            mn = min(mn, cnt);
        }
    }
    
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& e) {
        vector<vector<int>> adj(n);
        vector<int> count(n, 0);
        mn = INT_MAX;
        for(int i = 0; i < e.size(); i++) {
            adj[e[i][0]].push_back(e[i][1]);
            adj[e[i][1]].push_back(e[i][0]);
            count[e[i][0]]++;
            count[e[i][1]]++;
        }
        queue<int> q;
        for(int i = 0; i < n; i++) {
            if(count[i] <= 1)
                q.push(i);
        }
        while(n > 2) {
            int numLeafs = q.size();
            n -= numLeafs;
            for(int i = 0; i < numLeafs; i++) {
                int node = q.front();
                q.pop();
                for(auto neigh : adj[node]) {
                    if(--count[neigh] == 1) {
                        q.push(neigh);
                    }
                }
            }
        }
        vector<int> ret;
        while(!q.empty()) {
            ret.push_back(q.front());
            q.pop();
        }
        return ret;
    }
};
