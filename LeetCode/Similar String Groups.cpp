class Solution {
public:
    vector<int> parent;
    int clusters;
    
    void uni(int i, int j) {
        int u = find(i), v = find(j);
        if(u != v) {
            parent[u] = v;
            clusters--;
        }
    }
    
    int find(int u) {
        if(parent[u] == u)
            return u;
        return parent[u] = find(parent[u]);
    }
    
    bool isSimilar(string u, string v) {
        int n = 0;
        for(int i = 0; i < u.size(); i++) {
            if(u[i] != v[i] && ++n > 2)
                return false;
        }
        return true;
    }
    
    int numSimilarGroups(vector<string>& A) {
        int n = A.size();
        clusters = n;
        for(int i = 0; i < n; i++)
            parent.push_back(i);
        for(int i = 0; i < n; i++) {
            for(int j = i + 1; j < n; j++) {
                if(isSimilar(A[i], A[j])) {
                    uni(i, j);
                }
            }    
        }
        return clusters;
    }
};
