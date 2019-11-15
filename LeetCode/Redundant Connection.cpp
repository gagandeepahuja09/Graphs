class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        vector<int> p(2001);
        for(int i = 0; i <= 2000; i++)
            p[i] = i;
        vector<int> ret;
        for(auto v : edges) {
            int n1 = v[0], n2 = v[1];
            while(n1 != p[n1])
                n1 = p[n1];
            while(n2 != p[n2])
                n2 = p[n2];
            if(n1 == n2) {
                ret = v;
            }
            else
                p[n1] = n2;
        }
        return ret;    
    }
};
