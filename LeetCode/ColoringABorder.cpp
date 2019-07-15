class Solution {
public:
    void dfs(vector<vector<int>>& grid, int r0, int c0, int color) {
        if(r0 < 0 || r0 >= grid.size() || c0 < 0 || c0 >= grid[0].size() || grid[r0][c0] != color)
            return;
        grid[r0][c0] = -color;
        dfs(grid, r0 + 1, c0, color); dfs(grid, r0 - 1, c0, color); 
        dfs(grid, r0, c0 - 1, color); dfs(grid, r0, c0 + 1, color);
        if(r0 > 0 && r0 < grid.size() - 1 && c0 > 0 && c0 < grid[0].size() - 1 && color == abs(grid[r0 - 1][c0])
          && color == abs(grid[r0][c0 - 1]) && color == abs(grid[r0][c0 + 1]) && color == abs(grid[r0 + 1][c0])) {
            grid[r0][c0] = color;
        }
    }
    
    vector<vector<int>> colorBorder(vector<vector<int>>& grid, int r0, int c0, int color) {
        dfs(grid, r0, c0, grid[r0][c0]);
        for(int i = 0; i < grid.size(); i++) {
            for(int j = 0; j < grid[i].size(); j++) {
                if(grid[i][j] < 0)
                    grid[i][j] = color;
            }
        }
        return grid;
    }
};
