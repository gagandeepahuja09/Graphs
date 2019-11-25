class Solution {
public:
    bool validColor(vector<vector<int>>& g, vector<int>& colors, int color, int node) {
        if(colors[node] != 0) {
            return (colors[node] == color);
        }
        colors[node] = color;
        for(int next : g[node]) {
            if(!validColor(g, colors, -color, next))
                return false;
        }
        return true;
    }
    
    bool isBipartite(vector<vector<int>>& g) {
        int n = g.size();
        vector<int> colors(n);
        for(int i = 0; i < n; i++) {
            if(colors[i] == 0 && !validColor(g, colors, 1, i)) {
                return false;
            }
        }
        return true;
    }
};
