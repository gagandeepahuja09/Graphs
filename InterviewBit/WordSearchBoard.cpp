bool wordSearch(vector<string> &A, int x, int y, string B) {
    if(B.size() == 0) {
        return true;
    }
    vector<int> dx = {0, 1, -1,  0};
    vector<int> dy = {1, 0,  0, -1};
    bool ans = false;
    for(int i = 0; i < 4; i++) {
        int currX = x + dx[i];
        int currY = y + dy[i];
        if(currX >= 0 && currX < A.size() && currY >= 0 && currY < 
        A[0].size() && A[currX][currY] == B[0]) {
            ans = ans || wordSearch(A, currX, currY, B.substr(1));
        } 
    }
    return ans;
}

int Solution::exist(vector<string> &A, string B) {
    bool ans = false;
    for(int i = 0; i < A.size(); i++) {
        for(int j = 0; j < A[0].size(); j++) {
            if(A[i][j] == B[0]) {
                ans = ans || wordSearch(A, i, j, B.substr(1));
            }
        }
    }
    return ans;
}

