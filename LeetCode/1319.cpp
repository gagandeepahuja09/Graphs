class Solution {
public:
    int find(int u, vector<int>& parent) {
        if (parent[u] == -1)
            return u;
        return parent[u] = find(parent[u], parent);
    }
    
    int makeConnected(int n, vector<vector<int>>& con) {
        vector<int> parent(n, - 1);
        int extra = 0;
        for (int i = 0; i < con.size(); i++) {
            int u = con[i][0], v = con[i][1];
            u = find(u, parent);
            v = find(v, parent);
            if (u == v) {
                extra++;
            } else {
                parent[u] = v;
            }
        }
        int components = 0;
        for (int i = 0; i < n; i++) {
            components += (parent[i] == -1);
        }
        return (extra >= components - 1) ? components - 1 : -1;
    }
};
