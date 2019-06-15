/*
Minimum cost to connect cities

Given a city network having A nodes. The Roads of this city are damaged and you are asked to repair the roads.

Given a matrix B of size M x 3 which represents the road such that there is a road 
between B[i][0] and B[i][1] before the damage and cost of repairing this road is B[i][2]. 
you need to repair some of the roads with the minimum cost such that the city will get 
connected after repairing the roads. 
In other words, after repairing some of the the roads, every pair of the city will be 
reachable from one another.

*/
bool cmp(vector<int> a, vector<int> b) {
    return a[2] < b[2];
}

int find(int u, vector<int>& parent) {
    if(parent[u] == -1)
        return u;
    int root = find(parent[u], parent);
    return parent[u] = root;
}

int Solution::solve(int A, vector<vector<int> > &B) {
    sort(B.begin(), B.end(), cmp);
    vector<int> parent(A + 1, -1);
    int cost = 0;
    for(int i = 0; i < B.size(); i++) {
        int u = B[i][0], v = B[i][1];
        u = find(u, parent);
        v = find(v, parent);
        if(u != v) {
            cost += B[i][2];
            // dunion(u, v, parent);
            parent[u] = v;
        }
    }
    return cost;
}

