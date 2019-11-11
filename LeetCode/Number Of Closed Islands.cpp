class Solution {
public:
    void dfs(vector<vector<int>>& grid, int i, int j, bool &flag) {
        if(i < 0 || i >= grid.size() || j < 0 || j >= grid[0].size()) {
            flag = false;
            return;
        }
        if(grid[i][j] == 1 || grid[i][j] == -1) {
            return;
        }
        grid[i][j] = -1;
        dfs(grid, i, j + 1, flag); dfs(grid, i - 1, j, flag); dfs(grid, i + 1, j, flag); dfs(grid, i, j - 1, flag);
    }
    
    int closedIsland(vector<vector<int>>& grid) {
        int cnt = 0;
        for(int i = 0; i < grid.size(); i++) {
            for(int j = 0; j < grid[i].size(); j++) {
                if(grid[i][j] == 0) {
                    bool flag = true;
                    dfs(grid, i, j, flag);
                    if(flag)
                        cnt++;
                }
            }
        }
        return cnt;
    }
};
