class Solution {
public:
    unordered_set<string> vis;
    unordered_map<string, unordered_map<string, double>> mp;
    double dfs(string u, string v) {
        if(mp[u].find(v) != mp[u].end()) {
            return mp[u][v];
        }
        for(auto i : mp[u]) {
            if(vis.find(i.first) == vis.end()) {
                vis.insert(i.first);
                double curr = dfs(i.first, v);
                if(curr)
                    return i.second * curr;
            }
        }
        return 0;
    }
    
    vector<double> calcEquation(vector<vector<string>>& eq, vector<double>& v, vector<vector<string>>& q) {
        mp.clear();
        for(int i = 0; i < v.size(); i++) {
            mp[eq[i][0]].insert({ eq[i][1], v[i] });
            mp[eq[i][1]].insert({ eq[i][0], 1 / v[i] });
        }
        vector<double> ret;
        for(int i = 0; i < q.size(); i++) {
            vis.clear();
            string u = q[i][0], v = q[i][1];
            double ans = dfs(u, v);
            if(ans == 0)
                ret.push_back(-1.0);
            else    
                ret.push_back(ans);
        }
        return ret;
    }
};
