class Solution {
public:
    int minimumSemesters(int N, vector<vector<int>>& r) {
        vector<vector<int>> adj(N + 1);
        for(int i = 0; i < r.size(); i++) {
            adj[r[i][0]].push_back(r[i][1]);
        }
        vector<int> ind(N + 1, 0);
        
        for(int i = 1; i <= N; i++) {
            for(auto it = adj[i].begin(); it != adj[i].end(); it++) {
                ind[*it]++;
            }
        }
        
        int c = 0;
        queue<int> q;
        unordered_map<int, int> mp;
        for(int i = 1; i <= N; i++) {
            mp[ind[i]]++;
        }
        for(int i = 1; i <= N; i++) {
            if(ind[i] == 0) {
                q.push(i);
                c++;
            }
        }
        int cnt = 1;
        while(!q.empty()) {
            bool flag = false;
            int sz = q.size();
            for(int i = 0; i < sz; i++) {
                int u = q.front();
                ind[u]--;
                q.pop();
                for(auto it = adj[u].begin(); it != adj[u].end(); it++) {
                    if(--ind[*it] == 0) {
                        if(!flag) {
                            flag = true;
                            cnt++;
                        }
                        q.push(*it);
                        c++;
                    }
                }
            }
        }
        return c == N ? cnt : -1;
    }
};
