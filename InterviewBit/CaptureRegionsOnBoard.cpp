// Source : https://www.geeksforgeeks.org/given-matrix-o-x-replace-o-x-surrounded-x/

void dfs(vector<vector<char>>& A, int i, int j) {
    if(i >= A.size() || i < 0 || j >= A[0].size() || j < 0 || A[i][j] != '-')
        return;
    A[i][j] = '0';
    dfs(A, i+1, j);
    dfs(A, i-1, j);
    dfs(A, i, j+1);
    dfs(A, i, j-1);
}

void Solution::solve(vector<vector<char> > &A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    // Step - 1
    for(int i=0; i<A.size(); i++) {
        for(int j=0; j<A[0].size(); j++) {
            if(A[i][j] == '0')
                A[i][j] = '-';
        }
    }
    // Step - 2
    for(int i=0; i<A.size(); i++) {
        dfs(A, i, 0);
    }
    for(int j=0; j<A[0].size(); j++) {
        dfs(A, 0, j);
    }
    for(int i=0; i<A.size(); i++) {
        dfs(A, i, A.size() - 1);
    }
    for(int j=0; j<A[0].size(); j++) {
        dfs(A, A[0].size() - 1, j);
    }
    // Step - 3
    for(int i=0; i<A.size(); i++) {
        for(int j=0; j<A[0].size(); j++) {
            if(A[i][j] == '-')
                A[i][j] = 'X';
        }
    }
}

