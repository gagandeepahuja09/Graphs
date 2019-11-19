class Solution {
public:
    unordered_set<string> st;
    unordered_map<string, unordered_map<string, double>> adj;
    double dfs(string u, string v) {
        if(adj[u].find(v) != adj[u].end()) {
            return adj[u][v];
        }
        for(auto i : adj[u]) {
            if(st.find(i.first) == st.end()) {
                st.insert(i.first);
                double curr = dfs(i.first, v);
                if(curr)
                    return i.second * curr;
            }
        }
        return 0;
    }
    
    vector<double> calcEquation(vector<vector<string>>& eq, vector<double>& v, vector<vector<string>>& q) {
        adj.clear();
        vector<double> ret;
        for(int i = 0; i < v.size(); i++) {
            adj[eq[i][0]].insert({ eq[i][1], v[i] });
            adj[eq[i][1]].insert({ eq[i][0], 1 / v[i] });
        }
        for(auto i : q) {
            st.clear();
            double ans = dfs(i[0], i[1]);
            if(ans == 0)
                ret.push_back(-1.0);
            else
                ret.push_back(ans);
        }
        return ret;
    }
};
