class Solution {
public:
    void dfsRooms(int idx, vector<bool>& visited, vector<vector<int>>& rooms, int &visitedCount) {
        if (visited[idx]) {
            return;
        }
        visited[idx] = true;
        visitedCount++;
        for (int j = 0; j < rooms[idx].size(); j++) {
            dfsRooms(rooms[idx][j], visited, rooms, visitedCount);
        }
    }

    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n = rooms.size();
        vector<bool> visited(n, false);
        int visitedCount = 0;
        dfsRooms(0, visited, rooms, visitedCount);
        if (visitedCount == n) {
            return true;
        }
        return false;
    }
};
