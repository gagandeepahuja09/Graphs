void dfs(vector<vector<char>> &A, int i, int j) {
    if(i < 0 || i >= A.size() || j < 0 || j >= A[0].size() 
    || A[i][j] != 'O')
        return;
    A[i][j] = 'Y';
    dfs(A, i - 1, j);   dfs(A, i, j - 1);   dfs(A, i + 1, j);
    dfs(A, i, j + 1);
}

void Solution::solve(vector<vector<char> > &A) {
    int m = A.size(), n = A[0].size();
    for(int i = 0; i < m; i++) {
        if(A[i][0] == 'O') {
            dfs(A, i, 0);
        }
        if(A[i][n - 1] == 'O') {
            dfs(A, i, n - 1);
        }
    }
    
    for(int i = 0; i < n; i++) {
        if(A[0][i] == 'O') {
            dfs(A, 0, i);
        }
        if(A[m - 1][i] == 'O') {
            dfs(A, m - 1, i);
        }
    }
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            if(A[i][j] == 'O')
                A[i][j] = 'X';
        }
    }
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            if(A[i][j] == 'Y')
                A[i][j] = 'O';
        }
    }
}

