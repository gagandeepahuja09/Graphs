class Graph {
    unordered_map<int, vector<int>> adj;
    unordered_map<int, int> indegree;
public:
    Graph() {}
    
    Graph(int n) {
        adj = unordered_map<int, vector<int>>{};
        indegree = unordered_map<int, int>{};
        for (int i = 0; i < n; ++i) {
            indegree[i] = 0;
            adj[i] = vector<int>{};
        }
    }
    
    Graph(vector<int> &vec) {
        adj = unordered_map<int, vector<int>>{};
        indegree = unordered_map<int, int>{};
        for (const int &i : vec) {
            indegree[i] = 0;
            adj[i] = vector<int>{};
        }
    }
    
    void addEdge(int from, int to) {
        adj[from].push_back(to);
        indegree[to]++;
    }
    
    vector<int> sort() {
        vector<int> ans;
        queue<int> q;
        for(auto p : indegree) {
            if(p.second == 0) {
                q.push(p.first);
            }
        }
        while(!q.empty()) {
            int f = q.front();
            q.pop();
            ans.push_back(f);
            for(auto i : adj[f]) {
                if(--indegree[i] == 0) {
                    q.push(i);
                }
            }
        }
        return ans;
    }
};

class Solution {
public:
    vector<int> sortItems(int n, int m, vector<int>& group, vector<vector<int>>& beforeItems) {
        vector<vector<int>> groupItems(m);
        for(int i = 0; i < n; i++) {
            if(group[i] >= 0) {
                groupItems[group[i]].push_back(i);
            }
            else {
                group[i] = groupItems.size();
                groupItems.push_back({ i });
            }
        }
        Graph groupGraph = Graph(groupItems.size());
        vector<Graph> groupItemGraphs(groupItems.size());
        for(int i = 0; i < groupItems.size(); i++) {
            groupItemGraphs[i] = Graph(groupItems[i]);
        }
        for(int i = 0; i < n; i++) {
            for(int j : beforeItems[i]) {
                if(group[i] == group[j]) {
                    groupItemGraphs[group[i]].addEdge(j, i);
                }
                else {
                    groupGraph.addEdge(group[j], group[i]);
                }
            }
        }
        vector<int> groupOrder = groupGraph.sort();
        vector<int> ret;
        if(groupOrder.size() < groupItems.size())
            return ret;
        for(int i : groupOrder) {
            vector<int> order = groupItemGraphs[i].sort();
            if(order.size() < groupItems[i].size())
                return {};
            for(int j : order) {
                ret.push_back(j);
            }
        }
        return ret;
    }
};
