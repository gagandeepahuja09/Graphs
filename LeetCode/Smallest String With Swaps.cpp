class Solution {
public:
    int find(int u, vector<int>& parent) {
        if(parent[u] != u)
            parent[u] = find(parent[u], parent);
        return parent[u];
    }
    
    string smallestStringWithSwaps(string s, vector<vector<int>>& pairs) {
        int n = s.size();
        vector<int> parent(n);
        for(int i = 0; i < n; i++)
            parent[i] = i;
        for(int i = 0; i < pairs.size(); i++) {
            int u = pairs[i][0], v = pairs[i][1];
            int pu = find(u, parent), pv = find(v, parent);
            if(pu != pv) {
                parent[pv] = pu;
            }
        }
        vector<vector<int>> mp(n);
        for(int i = 0; i < s.size(); i++) {
            mp[find(i, parent)].push_back(i);
        }
        for(auto v : mp) {
            string curr;
            for(int i : v)
                curr += s[i];
            sort(curr.begin(), curr.end());
            for(int i = 0; i < v.size(); i++) {
                s[v[i]] = curr[i];
            }
        }
        return s;
    }
};
