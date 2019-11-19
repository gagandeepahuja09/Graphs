class Solution {
public:
    int find(int u) {
        if(parent[u] != u) {
            parent[u] = find(parent[u]);
        }
        return parent[u];
    }
    
    void uni(int u, int v) {
        int pu = find(u), pv = find(v);
        parent[pu] = pv;
    }
    
    vector<int> parent;
    int largestComponentSize(vector<int>& A) {
        int n = *max_element(A.begin(), A.end());
        // cout << n << endl;
        parent.resize(n + 1);
        for(int i = 1; i <= n; i++) {
            parent[i] = i;
        }
        for(int i = 0; i < A.size(); i++) {
            for(int j = 2; j * j <= A[i]; j++) {
                if(A[i] % j == 0) {
                    uni(A[i], j);
                    uni(A[i], A[i] / j);
                }
            }
        }
        int mx = 1;
        unordered_map<int, int> mp;
        for(int i = 0; i < A.size(); i++) {
            // cout << find(A[i]) << " ";
            mx = max(mx, ++mp[find(A[i])]);
        }
        return mx;
    }
};
