class Solution {
public:
    vector<int> dx = { -1, 1, 0, 0 , -1, 1,  1, -1 };
    vector<int> dy = { 0, 0, -1, 1 ,  1, -1, 1, -1 };
    
    bool isVal(vector<vector<char>>& A, int i, int j) {
        return (i >= 0 && i < A.size() && j >= 0 && j < A[0].size());
    }
    
    void dfs(vector<vector<char>>& A, int i, int j, vector<vector<int>>& vis) {
        if(i < 0 || j < 0 || i >= A.size() || j >= A[0].size() || vis[i][j])
            return;
        vis[i][j] = true;
        if(A[i][j] == 'M') {
            A[i][j] = 'X';
            return;
        }
        int count = 0;
        for(int k = 0; k < 8; k++) {
            int ci = i + dx[k], cj = j + dy[k];
            if(isVal(A, ci, cj) && (A[ci][cj] == 'M' || A[ci][cj] == 'X')) {
                count++;
            }
        }
        if(count > 0) {
            A[i][j] = count + '0';
        }
        else {
            A[i][j] = 'B';
            for(int k = 0; k < 8; k++) {
                dfs(A, i + dx[k], j + dy[k], vis);
            }
        }
    }
    
    vector<vector<char>> updateBoard(vector<vector<char>>& A, vector<int>& click) {
        vector<vector<int>> vis(A.size(), vector<int>(A[0].size(), false));
        dfs(A, click[0], click[1], vis);
        return A;
    }
};
