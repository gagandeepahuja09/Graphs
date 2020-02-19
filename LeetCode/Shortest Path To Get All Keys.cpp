class Solution {
public:
    vector<int> dx = { 0, 0, -1, 1 };
    vector<int> dy = { -1, 1, 0, 0 };
    int shortestPathAllKeys(vector<string>& g) {
        int n = g.size(), m = g[0].size(), targetMask = 0;
        queue<vector<int>> q;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(g[i][j] == '@') {
                    q.push({ 0, i, j, 0 });
                }
                if(g[i][j] >= 'a' && g[i][j] <= 'f')
                    targetMask |= (1 << (g[i][j] - 'a'));
            }
        }
        unordered_set<string> vis;
        while(!q.empty()) {
            auto temp = q.front();  q.pop();
            int mask = temp[0], x = temp[1], y = temp[2]
                , moves = temp[3];
            if(mask == targetMask) {
                return moves;
            }
            string state = to_string(mask) + " " + to_string(x) + " " + to_string(y);
            if(vis.count(state))
                continue;
            vis.insert(state);
            for(int i = 0; i < 4; i++) {
                int currx = x + dx[i], curry = y + dy[i], currMask = mask;
                if(currx < 0 || curry < 0 || currx >= n || curry >= m || g[currx][curry] == '#')
                    continue;
                char ch = g[currx][curry];
                if(ch >= 'a' && ch <= 'f')
                    currMask |= (1 << (int)(ch - 'a'));
                else if(ch >= 'A' && ch <= 'F' && ((currMask & (1 << (int)(ch - 'A'))) == 0)) {
                    continue;
                }
                q.push({ currMask, currx, curry, moves + 1 });
            }
        }
        return -1;
    }
};
