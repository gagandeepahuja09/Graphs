class Solution {
public:
    int expand(vector<vector<int>>& A, int i, int j, int color) {
        if(i < 0 || i >= A.size() || j < 0 || j >= A[0].size())
            return 0;
        if(A[i][j] == 0)
            A[i][j] = color + 1;
        return (A[i][j] == 1);
    }
    
    void dfs(vector<vector<int>>& A, int i, int j) {
        if(i < 0 || j < 0 || i >= A.size() || j >= A[0].size() || A[i][j] == 0 || A[i][j] == 2)
            return;
        A[i][j] = 2;
        dfs(A, i + 1, j);   dfs(A, i - 1, j);   dfs(A, i, j + 1);   dfs(A, i, j - 1);
    }
    
    int shortestBridge(vector<vector<int>>& A) {
        bool breakFlag = false;
        for(int i = 0; i < A.size(); i++) {
            if(breakFlag)
                break;
            for(int j = 0; j < A[0].size(); j++) {
                if(A[i][j] == 1) {
                    dfs(A, i, j);
                    breakFlag = true;
                    break;
                }
            }
        }
        
        for(int color = 2; ; color++) {
            for(int i = 0; i < A.size(); i++) {
                for(int j = 0; j < A[0].size(); j++) {
                    if(A[i][j] == color && (
                        expand(A, i - 1, j, color) || expand(A, i, j - 1, color) 
                        || expand(A, i + 1, j, color) || expand(A, i, j + 1, color)))
                        return color - 2;    
                }
            }
        }
    }
};
