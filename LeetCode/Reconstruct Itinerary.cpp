class Solution {
private:
    unordered_map<string, multiset<string>> g;
    void dfs(string u, vector<string>& ret) {
        while(g[u].size()) {
            string v = *g[u].begin();
            g[u].erase(g[u].begin());
            dfs(v, ret);
        }
        ret.push_back(u);
    }
    
public:        
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        for(auto t : tickets) {
            g[t[0]].insert(t[1]);
        }
        vector<string> ret;
        dfs("JFK", ret);
        reverse(ret.begin(), ret.end());
        return ret;
    }
};
