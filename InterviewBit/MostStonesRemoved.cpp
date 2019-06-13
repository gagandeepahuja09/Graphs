/*
Most Stones Removed

Given a matrix of integers A of size N x 2 describing coordinates of N stones placed in 2D plane. Now, a move consists of removing a stone that shares a column or row with another stone on the plane.

Find and return the largest number of moves you can make.

Input 1:
    A = [   [0, 0]
            [0, 1]
            [1, 0]
            [1, 2]
            [2, 2]
            [2, 1]   ]
Output 1:
    5
Explanation 1:
    One of the order of removing stones:
    1. Remove (2,1) as it shares row with (2,2)
        remaining stones ( (0,0), (0,1), (1,0), (1,2) and (2,2)).
    2. Remove (2,2) as it shares column with (1,2)
        remaining stones ( (0,0), (0,1), (1,0) and (1,2)).
    3. Remove (0,1) as it shares row with (0,0)
        remaining stones ( (0,0), (1,0) and (1,2)).
    4. Remove (1,2) as it shares row with (1,0)
        remaining stones ( (0,0) and (1,0)).
    5. Remove (0,0) as it shares column with (1,0)
        remaining stones ((1,0)).
   So the maximum number of moves is 5.

Input 2:
    A = [   [0, 0]
            [0, 2]
            [2, 0]
            [1, 1]
            [2, 2]   ]
Output 2:
    3
*/

int islands;
unordered_map<int, int> parent;

int find(int u) {
    if(parent.find(u) == parent.end()) {
        parent[u] = u;
        islands++;
    }
    if(u == parent[u])
        return u;
    int root = find(parent[u]);
    parent[u] = root;
    return root;
}

void dunion(int u, int v) {
    u = find(u);
    v = find(v);
    if(u != v) {
        islands--;
        parent[u] = v;
    }
}

int Solution::solve(vector<vector<int> > &A) {
    islands = 0;
    parent.clear();
    for(int i = 0; i < A.size(); i++)
        dunion(A[i][0], ~A[i][1]);
    return A.size() - islands;    
}

