class Solution {
public:
    int find(int u, vector<int>& parent) {
        if(parent[u] != u)
            parent[u] = find(parent[u], parent);
        return parent[u];
    }
    
    int findCircleNum(vector<vector<int>>& M) {
        unordered_map<int, int> mp;
        int n= M.size();
        vector<int> parent;
        vector<int> rank(n, 0);
        for(int i = 0; i < n; i++)
            parent.push_back(i);
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                if(i == j)
                    continue;
                if(M[i][j] == 1) {
                    int pi = find(i, parent), pj = find(j, parent);
                    if(pi != pj) {
                        if(rank[pi] > rank[pj]) {
                            parent[pj] = pi;
                        }
                        else {
                            parent[pi] = pj;
                            if(rank[pi] == rank[pj])
                                rank[pi]++;
                        }
                    }
                }
            }
        }
        for(int i = 0; i < n; i++) {
            mp[find(i, parent)]++;
        }
        return mp.size();
    }
};
