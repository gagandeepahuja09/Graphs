class Solution {
public:
    int maxDistance(vector<vector<int>>& grid) {
        queue<pair<int, int>> q;
        int n = grid.size(), m = grid[0].size();
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(!grid[i][j])
                    grid[i][j] = INT_MAX;
                else 
                    q.push({ i, j });
            }
        }
        
        vector<int> dx = { 0,  0, -1, 1 };
        vector<int> dy = { 1, -1,  0, 0 };
        
        while(!q.empty()) {
            auto p = q.front();
            q.pop();
            int x = p.first, y = p.second, dist = grid[x][y] + 1;
            for(int i = 0; i < 4; i++) {
                int cx = x + dx[i], cy = y + dy[i];
                if(cx >= 0 && cx < n && cy >= 0 && cy < m && grid[cx][cy] > dist) {
                    grid[cx][cy] = dist;
                    q.push({ cx, cy });
                }
            }
        }
        int ret = 0;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(grid[i][j] > 1 && grid[i][j] < INT_MAX)
                    ret = max(ret, grid[i][j]);
            }
        }
        return ret - 1;
    }
};
