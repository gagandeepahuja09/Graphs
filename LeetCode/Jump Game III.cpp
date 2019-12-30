class Solution {
public:
    bool canReach(vector<int>& A, int start) {
        int n = A.size();
        queue<int> q;
        vector<bool> vis(n, false);
        q.push(start);
        vis[start] = 1;
        while(!q.empty()) {
            int f = q.front();
            q.pop();
            if(A[f] == 0)
                return true;
            int ff = f + A[f];
            if(ff < A.size() && !vis[ff]) {
                q.push(ff);
                vis[ff] = 1;
            }
            int fb = f - A[f];
            if(fb >= 0 && !vis[fb]) {
                q.push(fb);
                vis[fb] = 1;
            }
        }
        return false;
    }
};
