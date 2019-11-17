class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& A) {
        queue<pair<int, pair<int, int>>> q;
        vector<vector<int>> ret(A.size(), vector<int>(A[0].size()));
        for(int i = 0; i < A.size(); i++) {
            for(int j = 0; j < A[0].size(); j++) {
                if(A[i][j] == 0) {
                    ret[i][j] = 0;
                    q.push({ i, { j, 0 }});
                }
            }
        }
        vector<int> dx = { -1,  0, 1, 0 };
        vector<int> dy = {  0, -1, 0, 1 };
        while(!q.empty()) {
            auto p = q.front();
            q.pop();
            int x = p.first, y = p.second.first, steps = p.second.second;
            A[x][y] = -1;
            ret[x][y] = steps;
            for(int i = 0; i < 4; i++) {
                int cx = x + dx[i], cy = y + dy[i];
                if(cx >= 0 && cx < A.size() && cy >= 0 && cy < A[0].size() && A[cx][cy] == 1) {
                    A[cx][cy] = -1;
                    q.push({ cx, { cy, steps + 1 }});
                }
            }
        }
        return ret;
    }
};
