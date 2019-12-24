class Solution {
public:
    bool isSafe(int x1, int y1, int x2, int y2, vector<vector<int>>& g, set<vector<int>>& visited) {
        return (x1 >= 0 && x2 >= 0 && x1 < g.size() && x2 < g.size() && y1 >= 0 && y2 >= 0 && y1 < g[0].size() && y2 <                  g[0].size() && !visited.count({ x1, y1, x2, y2 }) && g[x1][y1] == 0 && g[x2][y2] == 0);
    }
    
    int minimumMoves(vector<vector<int>>& g) {
        queue<vector<int>> q;
        set<vector<int>> vis;
        int n = g.size();
        vector<int> v = { 0, 0, 0, 1 };
        
        vector<int> target = { n - 1, n - 2, n - 1, n - 1 };
        if(isSafe(0, 0, 0, 1, g, vis)) {
            q.push(v);
            vis.insert(v);
        }
        int steps = 0;
        while(!q.empty()) {
            int sz = q.size();
            while(sz--) {
                auto f = q.front();
                q.pop();
                if(f == target)
                    return steps;
                int x1 = f[0], y1 = f[1], x2 = f[2], y2 = f[3];
                // cout << x1 << " " << y1 << " " << x2 << " " << y2 << endl;
                vector<int> nv;
                if(x1 == x2) {  // horizontal
                    if(isSafe(x1, y1, x1 + 1, y1, g, vis)) {
                        nv = { x1, y1, x1 + 1, y1 };   
                    }
                }
                else {          // vertical
                    if(isSafe(x1, y1, x1, y1 + 1, g, vis)) {
                        nv = { x1, y1, x1, y1 + 1 };    
                    }
                }
                if(nv.size() == 4) {
                    vis.insert(nv);
                    q.push(nv);
                }
                if(isSafe(x1 + 1, y1, x2 + 1, y2, g, vis)){
                    vector<int> v1 = { x1 + 1, y1, x2 + 1, y2 };  
                    vis.insert(v1);
                    q.push(v1);
                }
                if(isSafe(x1, y1 + 1, x2, y2 + 1, g, vis)) {
                    vector<int> v1 = { x1, y1 + 1, x2, y2 + 1 };  
                    vis.insert(v1);
                    q.push(v1);
                }
            }
            steps++;
        }
        return -1;
    }
};
