class Solution {
public:
    int ans;
    void dfs(vector<int>& st, vector<int>& cand, vector<vector<int>>& k, vector<vector<int>>& cb, vector<int>& ib, vector<int>& mp, vector<int>& vis, int v) {
        if(vis[v])
            return;
        ans += cand[v];
        vis[v] = 1;
        for(int j = 0; j < k[v].size(); j++) {
            int bx = k[v][j];
            st[bx] = 1;
            if(mp[bx]) {
                dfs(st, cand, k, cb, ib, mp, vis, bx);
            }
        }
        for(int j = 0; j < cb[v].size(); j++) {
            int bx = cb[v][j];
            mp[bx]++;
            if(st[bx]) {
                dfs(st, cand, k, cb, ib, mp, vis, bx);
            }
        }
    }
    
    int maxCandies(vector<int>& st, vector<int>& cand, vector<vector<int>>& k, vector<vector<int>>& cb, vector<int>& ib) {
        ans = 0;
        int n = st.size();
        vector<int> mp(n, 0);
        vector<int> vis(n, 0);
        for(int i = 0; i < ib.size(); i++) {
            dfs(st, cand, k, cb, ib, mp, vis, ib[i]);
        }
        return ans;
    }
};
