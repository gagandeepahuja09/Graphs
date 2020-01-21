class Solution {
public:
    int find(int i, vector<int>& parent) {
        if(parent[i] == -1)
            return i;
        return parent[i] = find(parent[i], parent);
    }
    
    int makeConnected(int n, vector<vector<int>>& con) {
        int extra = 0;
        vector<int> parent(n, -1);
        for(auto v : con) {
            int i = v[0], j = v[1];
            i = find(i, parent);    j = find(j, parent);
            if(i == j) {
                extra++;
            }
            else {
                parent[i] = j;
            }
        }
        int comps = 0;
        for(int i = 0; i < parent.size(); i++) {
            comps += (parent[i] == -1);
        }
        return comps - 1 <= extra ? comps - 1 : -1;
    }
};
