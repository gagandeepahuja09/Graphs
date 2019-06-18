/*
Shortest Distance in a Maze

Given a matrix of integers A of size N x M describing a maze. The maze consists of empty locations and walls. 1 represents a wall in a matrix and 0 represents an empty location in a wall.

There is a ball trapped in a maze. The ball can go through empty spaces by rolling up, down, left or right, but it won't stop rolling until hitting a wall. When the ball stops, it could choose the next direction.

Given two array of integers of size B and C of size 2 denoting the starting and destination position of the ball.

Find the shortest distance for the ball to stop at the destination. The distance is defined by the number of empty spaces traveled by the ball from the starting position (excluded) to the destination (included). If the ball cannot stop at the destination, return -1.

Note:

    Rows are numbered from top to bottom and columns are numbered from left to right.

    Assume the border of the maze are all walls.

    Both the starting position of the ball and the destination position of the ball exist on an empty space.

    Both the starting and destination positions will not be at the same position initially.



For Example

Input 1:
    A = [   [0, 0, 1, 0, 0]
            [0, 0, 0, 0, 0]
            [0, 0, 0, 1, 0]
            [1, 1, 0, 1, 1]
            [0, 0, 0, 0, 0]   ] 
    B = [0, 4]
    C = [4, 4]
Output 1:
    12
    Shortest path to the destination: left -> down -> left -> down -> right -> down -> right
    The total distance is 1 + 1 + 3 + 1 + 2 + 2 + 2 = 12.

Input 2:
    A = [   [0, 0, 1, 0, 0]
            [0, 0, 0, 0, 0]
            [0, 0, 0, 1, 0]
            [1, 1, 0, 1, 1]
            [0, 0, 0, 0, 0]  ]
    B = [0, 4]
    C = [3, 2]
    B = 3
Output 2:
    -1
*/

#define pii pair<int, pair<int, int>>

int Solution::solve(vector<vector<int> > &A, vector<int> &B, vector<int> &C) {
    queue<pii> q;
    q.push({ 0, { B[0], B[1] }});
    vector<vector<bool>> vis(A.size(), vector<bool>(A[0].size(), false));
    while(!q.empty()) {
        pii p = q.front();
        q.pop();
        int x = p.second.first, y = p.second.second;
        // cout<<x<<" "<<y<<endl;
        if(x == C[0] && y == C[1])
            return p.first;
        if(vis[x][y])
            continue;
        vis[x][y] = 1;    
        int k = x - 1, cnt = 0;
        while(k >= 0 && A[k][y] == 0) {
            // vis[k][y] = 1;
            cnt++;
            k--;
        }
        q.push({ p.first + cnt, { k + 1, y }});
        k = x + 1, cnt = 0; 
        while(k < A.size() && A[k][y] == 0) {
            // vis[k][y] = 1;
            k++;
            cnt++;
        }
        q.push({ p.first + cnt, { k - 1, y }});
        k = y - 1, cnt = 0;
        while(k >= 0 && A[x][k] == 0) {
            // vis[x][k] = 1;
            cnt++;
            k--;
        }
        q.push({ p.first + cnt, { x, k + 1 }});
        k = y + 1, cnt = 0; 
        while(k < A[0].size() && A[x][k] == 0) {
            // vis[x][k] = 1;
            cnt++;
            k++;
        }
        q.push({ p.first + cnt, { x, k - 1 }});
    }
    return -1;
}

