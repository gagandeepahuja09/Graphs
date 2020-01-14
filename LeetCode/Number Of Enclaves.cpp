class Solution {
public:
    int dfs(vector<vector<int>>& A, int i, int j) {
        if(i < 0 || i >= A.size() || j < 0 || j >= A[0].size() || A[i][j] == 0)
            return 0;
        A[i][j] = 0;
        return 1 + dfs(A, i + 1, j) + dfs(A, i - 1, j) + dfs(A, i, j - 1) + dfs(A, i , j + 1);
    }
    
    int countOnes(vector<vector<int>>& A, int ans = 0) {
        for(int i = 0; i < A.size(); i++) {
            for(int j = 0; j < A[0].size(); j++) {
                ans += A[i][j];
            }
        }
        return ans;
    }
    
    int numEnclaves(vector<vector<int>>& A) {
        int ones = countOnes(A);
        int count = 0, n = A.size(), m = A[0].size();
        for(int i = 0; i < m; i++) {
            if(A[0][i])
                count += dfs(A, 0, i);
            if(A[n - 1][i])
                count += dfs(A, n - 1, i);
        }
        for(int i = 0; i < n; i++) {
            if(A[i][0])
                count += dfs(A, i, 0);
            if(A[i][m - 1])
                count += dfs(A, i, m - 1);
        }
        //cout << count << endl;
        return ones - count;
    }
};
