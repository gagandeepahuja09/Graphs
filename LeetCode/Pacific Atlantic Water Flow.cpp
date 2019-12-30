class Solution {
public:
    vector<int> dx = { -1,  0,  1,  0 };
    vector<int> dy = {  0, -1, 0,   1 };
        
    void dfs(int i, int j, vector<vector<int>>& g, int prev, vector<vector<bool>>& vis) {
        if(i < 0 || i >= g.size() || j < 0 || j >= g[0].size() || vis[i][j] || g[i][j] < prev)
            return;
        vis[i][j] = true;
        for(int k = 0; k < 4; k++) {
            int x = i + dx[k], y = j + dy[k];
            dfs(x, y, g, g[i][j], vis);
        }
    }
    
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& matrix) {
        vector<vector<int>> ret;
        if(!matrix.size())
            return ret;
        int n = matrix.size(), m = matrix[0].size();
        vector<vector<bool>> vis1(n, vector<bool>(m, false));
        vector<vector<bool>> vis2(n, vector<bool>(m, false));
        for(int j = 0; j < m; j++) {
            dfs(0, j, matrix, INT_MIN, vis1);
            dfs(n - 1, j, matrix, INT_MIN, vis2);
        }
        for(int i = 0; i < n; i++) {
            dfs(i, 0, matrix, INT_MIN, vis1);
            dfs(i, m - 1, matrix, INT_MIN, vis2);
        }
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(vis1[i][j] && vis2[i][j])
                    ret.push_back({ i, j });
            }
        }
        return ret;
    }
};
