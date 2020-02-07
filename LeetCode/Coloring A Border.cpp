class Solution {
public:
    int mini, minj, maxi, maxj;
    void dfs(int i, int j, int col, vector<vector<int>>& g) {
        if(i < 0 || j < 0 || i >= g.size() || j >= g[0].size() || g[i][j] != col)
            return;
        g[i][j] = 0;
        dfs(i + 1, j, col, g); dfs(i - 1, j, col, g);
        dfs(i, j + 1, col, g); dfs(i, j - 1, col, g);
    }
    
    vector<vector<int>> colorBorder(vector<vector<int>>& g, int r0, int c0, int color) {
        int col = g[r0][c0];
        int n = g.size(), m = g[0].size();
        dfs(r0, c0, col, g);
        vector<vector<int>> temp = g;
        for(int i = 0; i < g.size(); i++) {
            for(int j = 0; j < g[0].size(); j++) {
                if(g[i][j] == 0) {
                    if(i + 1 < n && g[i + 1][j] == 0 && i - 1 >= 0 && g[i - 1][j] == 0 && j + 1 < m && g[i][j + 1] == 0  && j - 1 >= 0 && g[i][j - 1] == 0)
                        continue;
                    temp[i][j] = color;
                }
            }
        }
        for(int i = 0; i < n; i++)
            for(int j = 0; j < m; j++)
                if(temp[i][j] == 0)
                    temp[i][j] = col;
        return temp;
    }
};
