struct Position {
    pair<int,int> box, me;
    bool operator <(const Position& b) const {
        return make_pair(box, me) < make_pair(b.box, b.me);
    }
};

const int dRow[4] = { -1, 1, 0, 0 };
const int dCol[4] = { 0, 0, -1, 1 };

class Solution {
public:
    int minPushBox(vector<vector<char>>& grid) {
        const int H = grid.size();
        const int W = grid[0].size();
        auto available = [&](int row, int col) {
            return (row >= 0 && row < H && col >= 0 && col < W && grid[row][col] != '#');
        };
        pair<int, int> startBox, startMe, target;
        for(int row = 0; row < H; row++) {
            for(int col = 0; col < W; col++) {
                if(grid[row][col] == 'B') {
                    startBox = { row, col };
                }
                if(grid[row][col] == 'S') {
                    startMe = { row, col };
                }
                if(grid[row][col] == 'T') {
                    target = { row, col };
                }
            }
        }
        set<Position> processed;
        Position start{ startBox, startMe };
        vector<vector<Position>> q;
        q.push_back({ start });
        for(int currDist = 0; currDist < q.size(); currDist++) {
            for(int i = 0; i < q[currDist].size(); i++) {
                Position state = q[currDist][i];
                if(state.box == target) {
                    return currDist;
                }
                if(processed.count(state)) {
                    continue;
                }
                map<Position, int> dist;
                processed.insert(state);
                for(int dir = 0; dir < 4; dir++) {
                    int newRow = state.me.first + dRow[dir];
                    int newCol = state.me.second + dCol[dir];
                    dist[state] = currDist;
                    if(available(newRow, newCol)) {
                        pair<int, int> newMe = { newRow, newCol };
                        pair<int, int> newBox = state.box;
                        int L = 0;
                        if(newMe == newBox) {  // If I moved towards the box, then it is equivalent to pushing, now the box will also move in that dirn
                            L++;
                            newBox.first += dRow[dir];
                            newBox.second += dCol[dir];
                            if(!available(newBox.first, newBox.second))
                                continue;
                        }
                        Position newState{ newBox, newMe };
                        int dist2 = dist[state] + L;
                        if(dist.count(newState) == 0 || dist[newState] > dist2) {
                            dist[newState] = dist2;
                            while(dist2 >= q.size()) {
                                q.push_back({});
                            }
                            q[dist2].push_back(newState);
                        }
                    }
                }
            }
        }
        return -1;
    }
};
