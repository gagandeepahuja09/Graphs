class Solution {
public:
    vector<int> dx = { -1, 0, 1,  0 };
    vector<int> dy = { 0, 1,  0, -1 };
    
    int bfs(int sX, int sY, int eX, int eY, vector<vector<int>>& forest) {
        queue<pair<pair<int, int>, int>> q;
        int n = forest.size(), m = forest[0].size();
        vector<vector<int>> vis(n, vector<int>(m, 0));
        q.push({{ sX, sY}, 0});
        while(!q.empty()) {
            auto f = q.front();
            q.pop();
            int x = f.first.first, y = f.first.second, steps = f.second;
            vis[x][y] = 1;
            if(x == eX && y == eY) {
                return steps;
            }
            for(int i = 0; i < 4; i++) {
                int nX = x + dx[i], nY = y + dy[i];
                if(nX >= 0 && nX < n && nY >= 0 && nY < m && !vis[nX][nY] && forest[nX][nY] > 0) {
                    q.push({{ nX, nY }, steps + 1 });
                }
            }
        }
        return -1;
    }
    
    int cutOffTree(vector<vector<int>>& forest) {
        vector<vector<int>> points;
        for(int i = 0; i < forest.size(); i++) {
            for(int j = 0; j < forest[i].size(); j++) {
                if(forest[i][j] > 1) {
                    points.push_back({ forest[i][j], i, j });
                }
            }
        }
        if(points[0][0] == 0)
            return -1;
        sort(points.begin(), points.end());
        int total = 0;
        for(int i = 0, curX = 0, curY = 0; i < points.size(); i++) {
            int steps = bfs(curX, curY, points[i][1], points[i][2], forest);
            if(steps == -1)
                return steps;
            // cout << steps << endl;
            total += steps;
            curX = points[i][1];
            curY = points[i][2];
        }
        return total;
    }
};
