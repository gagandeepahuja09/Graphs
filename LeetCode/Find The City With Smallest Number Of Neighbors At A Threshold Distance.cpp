class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int th) {
        vector<vector<int>> dist(n, vector<int>(n, 1e8));
        for(auto e : edges) {
            int u = e[0], v = e[1];
            dist[u][v] = e[2];
            dist[v][u] = e[2];
        }
        int ans = 0;
        int minCount = n + 1;
        for(int i = 0; i < n; i++) {
            dist[i][i] = 0;
        }
        for(int k = 0; k < n; k++) {
            for(int i = 0; i < n; i++) {
                for(int j = 0; j < n; j++) {
                    if(dist[i][k] + dist[k][j] < dist[i][j])
                        dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
        
        for(int i = 0; i < n; i++) {
            int count = 0;
            for(int j = 0; j < n; j++) {
                if(dist[i][j] <= th)
                    count++;
            }
            if(count <= minCount) {
                minCount = count; 
                ans = i;
            }
        }
        return ans;
    }
};
