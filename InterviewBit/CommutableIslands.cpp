bool cmp(vector<int> v1, vector<int> v2) {
    return v1[2] < v2[2];
}

int find(int u, vector<int>& parent) {
    if(parent[u] == -1)
        return u;
    return find(parent[u], parent);    
}

int Solution::solve(int A, vector<vector<int> > &B) {
    sort(B.begin(), B.end(), cmp);
    int cost = 0;
    vector<int> parent(A + 1, -1);
    for(int i = 0; i < B.size(); i++) {
        int u = find(B[i][0], parent), v = find(B[i][1], parent);
        if(u != v) {
            parent[u] = v;
            cost += B[i][2];
        }
    }
    return cost;
}

