vector<vector<int> > Solution::solve(vector<vector<int> > &A) {
    int n = A.size();
    vector<vector<int>> dp(n, vector<int>(n, 0));
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            dp[i][j] = A[i][j];
        }
    }
    for(int k = 0; k < n; k++) {
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                if (dp[i][k] + dp[k][j] < dp[i][j])  
                    dp[i][j] = dp[i][k] + dp[k][j];  
            }
        }
    }
    return dp;
}

