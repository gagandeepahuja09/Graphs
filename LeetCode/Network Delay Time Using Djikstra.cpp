class Solution {
public:
    vector<int> dijkstra(vector<vector<pair<int, int>>>& g, int src) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push({ 0, src });
        int n = g.size();
        vector<int> ret(n, INT_MAX);
        while(!pq.empty()) {
            auto t = pq.top();
            pq.pop();
            int w = t.first, v = t.second;
            if(ret[v] != INT_MAX)
                continue;
            ret[v] = w;
            for(auto p : g[v]) {
                pq.push({ w + p.second, p.first });
            }
        }
        return ret;
    }
    
    int networkDelayTime(vector<vector<int>>& t, int N, int K) {
        vector<vector<pair<int, int>>> g(N);
        for(auto e : t) {
            g[e[0] - 1].push_back({ e[1] - 1, e[2] });
        }
        vector<int> ret = dijkstra(g, K - 1);
        int mx = 0;
        for(int i = 0; i < ret.size(); i++)
            mx = max(mx, ret[i]);
        return mx == INT_MAX ? -1 : mx;
    }
};
