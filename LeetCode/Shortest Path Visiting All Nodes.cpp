class Solution {
public:
    int shortestPathLength(vector<vector<int>>& A) {
        int n = A.size();
        int allVis = (1 << n) - 1;
        vector<vector<int>> dist(n, vector<int>(1 << n, 0));
        queue<pair<int, int>> q;
        int minSize = INT_MAX;
        for(int i = 0; i < n; i++) {
            minSize = min(minSize, (int)A[i].size());
        }
        for(int i = 0; i < n; i++) {
            if((int)A[i].size() == minSize) {
                // head, only this node covered
                q.push({ i, 1 << i });
            }
        }
        while(!q.empty()) {
            int head = q.front().first;
            int cover = q.front().second;
            q.pop();
            if(cover == allVis) {
                return dist[head][cover];
            }
            // cout << cover << endl;
            for(int i = 0; i < A[head].size(); i++) {
                int next = A[head][i];
                int newCover = cover | (1 << next);
                // Means there is already a shorter distance, so don't update
                if(dist[next][newCover])
                    continue;
                dist[next][newCover] = 1 + dist[head][cover];
                q.push({ next, newCover });
            }
        }
        return -1;
    }
};
