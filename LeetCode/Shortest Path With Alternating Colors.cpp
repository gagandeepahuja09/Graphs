class Solution {
public:
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& re, vector<vector<int>>& be) {
        vector<vector<pair<int, int>>> g(n);
        for(auto v : re) {
            g[v[0]].push_back({ v[1], 0 });
        }
        for(auto v : be) {
            g[v[0]].push_back({ v[1], 1 });
        }
        vector<vector<int>> vCost(n, vector<int>(2, 1e5));
        queue<pair<int, int>> q;
        q.push({ 0, 0 });
        q.push({ 0, 1 });
        vCost[0] = { 0, 0 };
        while(!q.empty()) {
            auto [i, c1] = q.front(); q.pop();
            for(auto [j, c2] : g[i]) {
                if(c2 == c1 || vCost[j][c2] != 1e5)
                    continue;
                vCost[j][c2] = 1 + vCost[i][c1];
                q.push({ j, c2 });
            }
        }
        vector<int> ret;
        for(auto v : vCost) {
            int ans = min(v[0], v[1]);
            if(ans == 1e5)
                ans = -1;
            ret.push_back(ans);
        }
        return ret;
    }
};
