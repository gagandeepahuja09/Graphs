class Solution {
public:
    bool isValidExit(int i, int j, int steps, vector<vector<char>>& maze) {
        return steps > 0 && ((i == 0 || i == maze.size() - 1) || (j == 0 || j == maze[0].size() - 1)) && maze[i][j] == '.';
    }

    bool isUnreachablePoint(int i, int j, vector<vector<char>>& maze) {
        return i < 0 || i >= maze.size() || j < 0 || j >= maze[0].size() || maze[i][j] != '.';
    }

    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        // [i, j, num_steps]
        queue<vector<int>> q;
        int n = maze.size(), m = maze[0].size();
        vector<vector<bool>> visited(n, vector<bool>(m, false));
        int i = entrance[0], j = entrance[1];
        if (maze[i][j] == '+') {
            return -1;
        }
        q.push({ i, j, 0 });
        while(!q.empty()) {
            vector<int> tp = q.front();
            q.pop();
            int i = tp[0], j = tp[1], steps = tp[2];
            if (isUnreachablePoint(i, j, maze) || visited[i][j]) {
                continue;
            }
            visited[i][j] = true;
            // cout << i << " " << j << " " << steps << endl;
            if (isValidExit(i, j, steps, maze)) {
                return steps;
            }
            q.push({ i + 1, j, steps + 1 });
            q.push({ i, j + 1, steps + 1 });
            q.push({ i - 1, j, steps + 1 });
            q.push({ i, j - 1, steps + 1 });
        }
        return -1;
    }
};
