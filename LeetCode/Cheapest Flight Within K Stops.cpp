class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& f, int src, int dst, int K) {
        vector<int> dp(n, 1e8);
        dp[src] = 0;
        for(int i = 0; i <= K; i++) {
            vector<int> next(dp);
            for(auto e : f) {
                next[e[1]] = min(next[e[1]], dp[e[0]] + e[2]);
            }
            dp = next;
        }
        return dp[dst] == 1e8 ? -1 : dp[dst];
    }
};
