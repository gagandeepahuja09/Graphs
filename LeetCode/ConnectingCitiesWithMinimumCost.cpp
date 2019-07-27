class Solution {
public:
    
    static bool cmp(vector<int> a, vector<int> b) {
        return a[2] < b[2];
    }

    int find(int u, vector<int>& parent) {
        if(parent[u] == -1)
            return u;
        int root = find(parent[u], parent);
        return parent[u] = root;
    }
    
    int minimumCost(int A, vector<vector<int>>& B) {
        sort(B.begin(), B.end(), cmp);
        vector<int> parent(A + 1, -1);
        int cost = 0;
        int clusters = A;
        for(int i = 0; i < B.size(); i++) {
            int u = B[i][0], v = B[i][1];
            u = find(u, parent);
            v = find(v, parent);
            if(u != v) {
                clusters--;
                cost += B[i][2];
                parent[u] = v;
            }
        }
        return clusters == 1 ? cost : -1;    
    }
};
