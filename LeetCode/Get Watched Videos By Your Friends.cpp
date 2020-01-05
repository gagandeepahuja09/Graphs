class Solution {
public:
    vector<string> watchedVideosByFriends(vector<vector<string>>& w, vector<vector<int>>& fr, int id, int level) {
        queue<int> q;
        int l = 0;
        q.push(id);
        int n = fr.size();
        vector<int> vis(n, 0);
        unordered_map<string, int> mp;
        while(!q.empty()) {
            int sz = q.size();
            if(l > level)   break;
            for(int i = 0; i < sz; i++) {
                int f = q.front();
                q.pop();
                if(vis[f])
                    continue;
                vis[f] = 1;
                if(l == level) {
                    for(int j = 0; j < w[f].size(); j++) {
                        mp[w[f][j]]++;
                    }
                }
                for(int j = 0; j < fr[f].size(); j++) {
                    q.push(fr[f][j]);
                }
            }
            l++;
        }
        vector<pair<int, string>> pr;
        vector<string> ret;
        for(auto it : mp) {
            pr.push_back({ it.second, it.first });
        }
        sort(pr.begin(), pr.end());
        for(auto it : pr) {
            ret.push_back(it.second);
        }
        return ret;
    }
};
