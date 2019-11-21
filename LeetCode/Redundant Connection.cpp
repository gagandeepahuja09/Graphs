class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& e) {
        vector<int> ret;
        vector<int> parent(e.size() + 1);
        for(int i = 1; i <= e.size(); i++) {
            parent[i] = i;
        }
        for(int i = 0; i < e.size(); i++) {
            int u = e[i][0], v = e[i][1];
            while(u != parent[u])
                u = parent[u];
            while(v != parent[v])
                v = parent[v];
            if(u != v) {
                parent[u] = v;
            }
            else {
                vector<int> v = { min(e[i][0], e[i][1]), max(e[i][0], e[i][1]) };
                ret = v;
            }
        }
        return ret;
    }
};
