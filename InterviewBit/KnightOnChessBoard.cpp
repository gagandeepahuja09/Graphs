class Knight {
    public:
    int x, y, timeStamp;
    Knight(int x, int y, int timeStamp) {
        this -> x = x;
        this -> y = y;
        this -> timeStamp = timeStamp;
    }
};

int Solution::knight(int N, int M, int x1, int y1, int x2, int y2) {
    queue<Knight> q;
    q.push(Knight(x1, y1, 0));
    vector<vector<bool>> vis(N+1, vector<bool>(M+1, false));
    vis[x1][y1] = true;
    vector<int> dx = { -1, 1, -1,  1, 2, -2,  2, -2 };
    vector<int> dy = {  2, 2, -2, -2, 1,  1, -1, -1 };
    while(!q.empty()) {
        Knight top = q.front();
        q.pop();
        if(top.x == x2 && top.y == y2)
            return top.timeStamp;
        for(int i=0; i<8; i++) {
            int x = top.x + dx[i];
            int y = top.y + dy[i];
            int currTime = top.timeStamp + 1;
            if(x <= N && x > 0 && y <= M && y > 0 && !vis[x][y]) {
                q.push(Knight(x, y, currTime));
                vis[x][y] = true;
            }
        }
    }
    return -1;
}

