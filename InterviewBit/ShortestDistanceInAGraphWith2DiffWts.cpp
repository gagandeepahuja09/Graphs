/*
Shortest Distance in a graph with two different weights

Given a weighted undirected graph having A nodes. A matrix B of size M x 3 is given which represents the edges such that there is an edge between B[i][0] and B[i][1] having weight B[i][2]. B[i][2] can be either 1 or 2. Given a source node C and a destination node D.

Find the shortest distance from C to D. If it is impossible to reach node D from C then return -1.

You are expected to do it in Time Complexity of O(A + M).

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
The fourth argumnet is an integer D. 

Output Format

Return the shortest distance from C to D. If it is impossible to reach node D from C then return -1.

Constraints

1 <= A <= 100000
0 <= B[i][0], B[i][1] < A
1 <= B[i][2] <= 2;
0 <= C < A
0 <= D < A

For Example

Input 1:
    A = 6
    B = [   [2, 5, 1]
            [1, 3, 1] 
            [0, 5, 2] 
            [0, 2, 2] 
            [1, 4, 1] 
            [0, 1, 1] ] 
    C = 3
    D = 2
Output 1:
    4

Input 2:
    A = 5
    B = [   [0, 2, 1]
            [0, 4, 2] 
            [1, 3, 1]
            [1, 4, 1]
            [0, 1, 1] 
            [2, 4, 1]
            [3, 4, 2] 
            [1, 2, 1]  ] 
    C = 1
    D = 3
Output 2:
    1
*/

int Solution::solve(int A, vector<vector<int> > &B, int C, int D) {
    int nm = B.size();
    vector<vector<int>> adj(A + nm);
    vector<bool> vis(nm + A, false);
    int k=A;
    for(int i = 0; i < B.size(); i++) {
        int u = B[i][0], v = B[i][1], w = B[i][2];
        if(w == 1) {
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        else {
            adj[u].push_back(k);
            adj[k].push_back(u);
            adj[k].push_back(v);
            adj[v].push_back(k);
            k++;
        }
    }
    queue<pair<int, int>> q;
    q.push({ C, 0 });
    while(!q.empty()) {
        int t = q.front().first;
        int dist = q.front().second;
        q.pop();
        if(vis[t])
            continue;
        if(t == D) {
            return dist;
        }
        vis[t] = true;
        for(int i = 0; i < adj[t].size(); i++) {
            if(!vis[adj[t][i]]) {
                q.push({ adj[t][i], dist + 1 });
            }
        }
    }
    return -1;
}

