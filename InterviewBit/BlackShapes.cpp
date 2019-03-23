void dfs(vector<string> &A, int i, int j, int m, int n) {
    if(i >= m || j >= n || i < 0 || j < 0 || A[i][j] != 'X')
        return;
    // cout << i << j << " ";    
    A[i][j] = '0';
    dfs(A, i+1, j, m, n);
    dfs(A, i, j+1, m, n);
    dfs(A, i-1, j, m, n);
    dfs(A, i, j-1, m, n);
}

int Solution::black(vector<string> &A) {
    int m = A.size();
    int n = A[0].size();
    int cnt = 0;
    for(int i=0; i<m; i++) {
        for(int j=0; j<n; j++) {
            if(A[i][j] == 'X') {
                dfs(A, i, j, m, n);
                    cnt++;
            }
        }
    }
    return cnt;
}

