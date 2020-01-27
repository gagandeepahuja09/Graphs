class Solution {
public:
    vector<int> parent;
    int find(int u) {
        if(parent[u] == u)
            return u;
        return parent[u] = find(parent[u]);
    }
    
    void uni(int u, int v) {
        u = find(u); v = find(v);
        if(u != v) {
            parent[u] = v;
        }
    }
    
    int removeStones(vector<vector<int>>& stones) {
        parent.resize(20002);
        for(int i = 0; i < 20002; i++) {
            parent[i] = i;
        }
        for(int i = 0; i < stones.size(); i++) {
            uni(stones[i][0], stones[i][1] + 10001);
        }
        unordered_set<int> parents;
        for(int i = 0; i < stones.size(); i++) {
            parents.insert(find(stones[i][0]));
            parents.insert(find(stones[i][1] + 10001));
        }
        return stones.size() - parents.size();
    }
};
