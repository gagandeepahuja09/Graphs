#define pii pair<int, pair<int, int>>

int Solution::solve(vector<vector<int> > &A) {
    queue<pii> q;
    for(int i = 0; i < A.size(); i++) {
        for(int j = 0; j < A[0].size(); j++) {
            if(A[i][j] == 2) {
                q.push({0, { i, j }});
            }
        }
    }
    int mx = 0;
    while(!q.empty()) {
        pii p = q.front();
        q.pop();
        mx = max(mx, p.first);
        vector<int> dx = { 0, 1, 0, -1};
        vector<int> dy = { 1, 0, -1, 0};
        for(int i = 0; i < 4; i++) {
            int x = p.second.first + dx[i];
            int y = p.second.second + dy[i];
            if(x >= 0 && y >= 0 && x < A.size() && y < A[0].size() && A[x][y] == 1) {
                A[x][y] = 0;
                q.push({ p.first + 1, { x, y }});
            }
        }
    }
    for(int i = 0; i < A.size(); i++) {
        for(int j = 0; j < A[0].size(); j++) {
            if(A[i][j] == 1)
                return -1;
        }
    }
    return mx;
}

