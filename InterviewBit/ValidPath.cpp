string Solution::solve(int x, int y, int N, int R, vector<int> &E, 
vector<int> &F) {
    int rect[x + 1][y + 1];
    memset(rect, 0, sizeof rect);
    for(int i = 0; i <= x; i++) {
        for(int j = 0; j <= y; j++) {
            for(int k = 0; k < N; k++) {
                if(sqrt(pow(E[k] - i, 2) + pow(F[k] - j, 2)) <= R) {
                    rect[i][j] = 1;
                    break;
                }
            }
        }
    }
    if(rect[0][0] == 1 || rect[x][y] == 1)
        return "NO";
    queue<pair<int, int>> q;
    q.push({ 0, 0 });
    rect[0][0] = 1;
    while(!q.empty()) {
        pair<int, int> p = q.front();
        int currX = p.first;
        int currY = p.second;
        q.pop();
        
        if(currX == x && currY == y)
            return "YES";
        vector<int> dx = { 0, 1,  0, -1, 1,  1, -1, -1};
        vector<int> dy = { 1, 0, -1,  0, 1, -1,  1, -1};
        for(int i = 0; i < 8; i++) {
            int nextX = currX + dx[i];
            int nextY = currY + dy[i];
            if(nextX >= 0 && nextX <= x && nextY >= 0 && nextY <= y
            && rect[nextX][nextY] == 0) {
                q.push({ nextX, nextY });
                rect[nextX][nextY] = 1;
            }
        }
    }
    return rect[x][y] == 1 ? "YES" : "NO";
}

