class Solution {
public:
    int numBusesToDestination(vector<vector<int>>& routes, int s, int t) {
        unordered_map<int, vector<int>> toRoutes;
        for(int i = 0; i < routes.size(); i++) {
            for(int j : routes[i]) {
                toRoutes[j].push_back(i);
            }
        }
        unordered_set<int> vis;
        queue<vector<int>> q;
        q.push({ s, 0 });
        vis.insert(s);
        while(!q.empty()) {
            auto temp = q.front();
            int bus = temp[0], numBuses = temp[1];
            if(bus == t)
                return numBuses;
            q.pop();
            for(int i : toRoutes[bus]) {
                for(int j : routes[i]) {
                    if(!vis.count(j)) {
                        vis.insert(j);
                        q.push({ j, numBuses + 1 });
                    }
                }
                routes[i].clear();
            }
        }
        return -1;
    }
};
