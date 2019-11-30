class Solution {
public:
    int dfs(int u, vector<unordered_set<int>>& adj, vector<int>& v, vector<bool>& f) {
        int sum = v[u];
        for(auto i : adj[u]) {
            sum += dfs(i, adj, v, f);
        }
        if(sum == 0) {
            f[u] = true;
        }
        return sum;
    }


    
    int dfs(int u, vector<unordered_set<int>>& adj, vector<bool>& f) {
        if(f[u])
            return 0;
        int ans = 1;
        for(int i : adj[u]) {
            ans += dfs(i, adj, f);
        }
        return ans;
    }
    
    int deleteTreeNodes(int n, vector<int>& p, vector<int>& v) {
        vector<unordered_set<int>> adj(n);
        vector<bool> f(n, false);
        for(int i = 0; i < p.size(); i++) {
            int val = p[i];
            if(p[i] != -1) {
                adj[p[i]].insert(i);
            }
        }
        dfs(0, adj, v, f);
        return dfs(0, adj, f);
    }
};
