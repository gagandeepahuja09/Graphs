/*Given a rooted tree of A nodes rooted at node 0. Each node has some value. An array of integer B is given which describes the value at the node i.e. node i has value B[i].

A matrix C of size M x 2 is given describing the edges of the tree i.e. there is an edge between C[i][0] and C[i][1] in the tree.

Xor sum of node i is defined as the xor of values of all the nodes in the subtree of i.

You are required to find an array of integer D of size 2 where

    D[i][0]: Max Xor Sum among all nodes.
    D[i][1]: Count of nodes which have maximum xorsum.

Find and return the integer array D.*/

int dfs(int i, vector<vector<int>>& adj, vector<bool>& vis, vector<int>& memo, 
vector<int>& B) {
    if(vis[i])
        return 0;
    vis[i] = true;    
    int ans = B[i];
    for(int j = 0; j < adj[i].size(); j++) {
        ans ^= dfs(adj[i][j], adj, vis, memo, B);
    }
    return memo[i] = ans;
}

vector<int> Solution::solve(int A, vector<int> &B, vector<vector<int> > &C) {
    vector<vector<int>> adj(A);
    for(int i = 0; i < C.size(); i++) {
        adj[C[i][0]].push_back(C[i][1]);
        adj[C[i][1]].push_back(C[i][0]);
    }
    vector<int> memo(A, 0); 
    vector<bool> vis(A, false);
    dfs(0, adj, vis, memo, B);
    int mx = 0, cnt = 0;
    for(int i = 0; i < A; i++) {
        mx = max(mx, memo[i]);
    }
    for(int i = 0; i < A; i++) {
        if(memo[i] == mx)
            cnt++;
    }
    return { mx, cnt };
}

