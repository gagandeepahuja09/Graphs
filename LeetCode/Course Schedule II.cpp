class Solution {
public:
    vector<int> findOrder(int n, vector<vector<int>>& pre) {
        vector<vector<int>> adj(n);
        vector<int> ind(n, 0);
        
        for(int i = 0; i < pre.size(); i++) {
            adj[pre[i][1]].push_back(pre[i][0]);
            ind[pre[i][0]]++;
        }
        queue<int> q;
        for(int i = 0; i < ind.size(); i++) {
            if(!ind[i])
                q.push(i), ind[i]--;
        }
        vector<int> ret;
        while(!q.empty()) {
            int t = q.front();
            q.pop();
            ret.push_back(t);
            for(int i = 0; i < adj[t].size(); i++) {
                --ind[adj[t][i]];
            }
            for(int i = 0; i < n; i++) {
                if(!ind[i])
                   q.push(i), ind[i]--;
            }
        }
        vector<int> v;
        return (ret.size() == n) ? ret : v;
    }
};
