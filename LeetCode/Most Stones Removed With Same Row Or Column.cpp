class Solution {
public:
    int find(int u, vector<int>& parent) {
        if(parent[u] != u) {
            parent[u] = find(parent[u], parent);
        }
        return parent[u];
    }
    
    void uni(int u, int v, vector<int>& parent) {
        int x = find(u, parent), y = find(v, parent);
        parent[x] = y;
    }
    
    int removeStones(vector<vector<int>>& stones) {
        vector<int> parent(20001);
        unordered_set<int> seen;
        for(int i = 0; i < parent.size(); i++)
            parent[i] = i;
        for(int i = 0; i < stones.size(); i++) {
            int x = stones[i][0], y = stones[i][1];
            uni(x, y + 10001, parent);
        }
        for(int i = 0; i < stones.size(); i++) {
            int x = stones[i][0], y = stones[i][1];
            seen.insert(find(x, parent));
        }
        
        return stones.size() - seen.size();
    }
};
