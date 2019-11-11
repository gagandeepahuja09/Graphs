class Solution {
public:
    int clusters;
    vector<int> parent;
    bool isSimilar(string s, string t) {
        int cnt = 0;
        if(s.size() != t.size())    return false;
        for(int i = 0; i < s.size(); i++) {
            if(s[i] != t[i])    cnt++;
        }
        return (cnt <= 2);
    }
    
    int find(int u) {
        if(u != parent[u]) {
            parent[u] = find(parent[u]);
        }
        return parent[u];
    }
    
    void uni(int u, int v) {
        int pu = find(u), pv = find(v);
        if(pu != pv) {
            parent[pu] = pv;
            clusters--;
        }
    }
    
    int numSimilarGroups(vector<string>& A) {
        int n = A.size();
        clusters = n;
        parent.resize(n);
        for(int i = 0; i < n; i++)
            parent[i] = i;
        for(int i = 0; i < n; i++) {
            for(int j = i + 1; j < n; j++) {
                if(isSimilar(A[i], A[j])) {
                    uni(i, j);
                    // cout << "Yes";
                }
            }
        }
        return clusters;
    }
};
