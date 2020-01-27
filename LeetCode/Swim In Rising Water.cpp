class Solution {
public:
    vector<int> dx = { -1, 1, 0, 0 };
    vector<int> dy = { 0, 0, -1, 1 };
    
    bool isValid(int i, int j, vector<vector<int>>& grid) {
        return (i >= 0 && j >= 0 && i < grid.size() && j < grid.size() && grid[i][j] < 1e8);
    }
    
    int swimInWater(vector<vector<int>>& grid) {
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
        int n = grid.size();
        pq.push({ grid[0][0], 0, 0 });
        int ret = 0;
        while(!pq.empty()) {
            auto v = pq.top();
            pq.pop();
            ret = max(ret, v[0]);
            // cout << ret << endl;
            int x = v[1], y = v[2];
            grid[x][y] = 1e8;;
            if(x == n - 1 && y == n - 1)
                return ret;
            for(int i = 0; i < 4; i++) {
                int cx = x + dx[i], cy = y + dy[i];
                if(isValid(cx, cy, grid)) {
                    pq.push({ grid[cx][cy], cx, cy });    
                }
            }
        }
        return n * n - 1;
    }
};
