class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int N, int K) {
        vector<int> dist(N + 1, INT_MAX);
        dist[0] = 0;
        vector<vector<pair<int, int>>> adj(N + 1);
        for(auto t : times) {
            adj[t[0]].push_back({ t[1], t[2] });    
        }
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push({ 0, K });
        while(!pq.empty()) {
            int node = pq.top().second, currDist = pq.top().first;
            pq.pop();
            if(dist[node] != INT_MAX)
                continue;
            dist[node] = currDist;
            for(auto p : adj[node]) {
                pq.push({ currDist + p.second, p.first });
            }
        }
        int delay = *max_element(dist.begin(), dist.end());
        return delay == INT_MAX ? -1 : delay;
    }
};
