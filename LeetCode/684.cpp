class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& e) {
        int n = e.size();
        vector<int> parent(n + 1);
        vector<int> ret;
        for (int i = 1; i <= n; i++)
            parent[i] = i;
        for (int i = 0; i < n; i++) {
            int u = e[i][0], v = e[i][1];
            while (u != parent[u])
                u = parent[u];
            while (v != parent[v])
                v = parent[v];
            if (u != v) {
                parent[u] = v;
            } else {
                vector<int> v = { min(e[i][0], e[i][1]), max(e[i][0], e[i][1]) };
                ret = v;
            }
        }
        return ret;
    }
};
