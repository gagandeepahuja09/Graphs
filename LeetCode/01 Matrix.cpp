class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        queue<vector<int>> q;
        for(int i = 0; i < mat.size(); i++) {
            for(int j = 0; j < mat[0].size(); j++) {
                if(mat[i][j] == 0) {
                    q.push({ i, j, 0 });
                }
                else {
                    mat[i][j] = -2;
                }
            }
        }
        vector<int> dx  = { -1, 0, 1, 0};
        vector<int> dy  = { 0, -1, 0, 1};
        while(!q.empty()) {
            auto f = q.front();
            q.pop();
            int x = f[0], y = f[1], steps = f[2];
            if(x < 0 || x >= mat.size() || y < 0 || y >= mat[0].size() || mat[x][y] == -1 || mat[x][y] > 0) {
                continue;
            }
            for(int i = 0; i < 4; i++) {
                int cx = x + dx[i], cy = y + dy[i];
                q.push({ cx, cy, steps + 1});
            }
            if(mat[x][y] == 0) {
                mat[x][y] = -1;
            }
            if(mat[x][y] == -2) {
                mat[x][y] = steps;
            }
        }
        for(int i = 0; i < mat.size(); i++) {
            for(int j = 0; j < mat[0].size(); j++) {
                if(mat[i][j] == -1)
                    mat[i][j] = 0; 
            }
        }
        return mat;
    }
};
