/*
Dijsktra

Given a weighted undirected graph having A nodes. A matrix B of size M x 3 is given which represents the edges such that there is an edge between B[i][0] and B[i][1] having weight B[i][2]. Given the source node C.

You have to find an integer array D of size A such that

D[i] : Shortest distance form the C node to node i. if node i is not reachable from C then -1.

Note:

    There are no self-loops in the graph.

    No multiple edges between two pair of vertices.

    The graph may or may not be connected.

    Nodes are Numbered from 0 to A-1.

    Your solution will run on multiple testcases. If you are using global variables make sure to clear them.


Input Format

The first argument given is an integer A.
The second argument given is the matrix B.
The third argument given is an integer C.

Output Format

Return the integer array D.

Constraints

1 <= A <= 100000
0<= B[i][0],B[i][1] < A
0 <= B[i][2] <= 1000;
0 <= C < A

For Example

Input 1:
    A = 6
    B = [   [0, 4, 9]
            [3, 4, 6] 
            [1, 2, 1] 
            [2, 5, 1] 
            [2, 4, 5] 
            [0, 3, 7] 
            [0, 1, 1] 
            [4, 5, 7] 
            [0, 5, 1] ] 
    C = 4
Output 1:
    D = [7, 6, 5, 6, 0, 6]

Input 2:
    A = 5
    B = [   [0, 3, 4]
            [2, 3, 3] 
            [0, 1, 9] 
            [3, 4, 10] 
            [1, 3, 8]  ] 
    C = 4
Output 2:
    D = [14, 18, 13, 10, 0]

×
-->*/



vector<int> Solution::solve(int A, vector<vector<int> > &B, int C) {
    vector<vector<pair<int, int>>> adj(A);
    bool vis[A];
    memset(vis, false, sizeof vis);
    for(int i = 0; i < B.size(); i++) {
        adj[B[i][0]].push_back({ B[i][1], B[i][2] });
        adj[B[i][1]].push_back({ B[i][0], B[i][2] });
    }
    vector<int> distance(A, INT_MAX);
    distance[C] = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({ 0, C });
    while(!pq.empty()) {
        pair<int, int> p = pq.top();
        pq.pop();
        int dist = p.first;
        int node = p.second;
        vis[node] = true;
        for(int i = 0; i < adj[node].size(); i++) {
            int child = adj[node][i].first;
            int wt = adj[node][i].second;
            if(!vis[child]) {
                if(dist + wt < distance[child])
                    distance[child] = dist + wt;
                pq.push({ distance[child], child });    
            }
        }
    }
    for(int i = 0; i < distance.size(); i++)
        if(distance[i] == INT_MAX)
            distance[i] = -1;
    return distance;
}

