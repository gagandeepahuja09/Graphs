class Solution {
public:
    string findSmallestRegion(vector<vector<string>>& regions, string r1, string r2) {
        unordered_map<string, string> mp;
        for(int i = 0; i < regions.size(); i++) {
            vector<string> v = regions[i];
            for(int j = 1; j < v.size(); j++) {
                mp[v[j]] = v[0];
            }
        }
        queue<string> q;
        q.push(r1);
        vector<string> v;
        while(!q.empty()) {
            auto f = q.front();
            q.pop();
            v.push_back(f);
            if(mp.find(f) != mp.end())
                q.push(mp[f]);
        }
        q.push(r2);
        unordered_set<string> st;
        while(!q.empty()) {
            auto f = q.front();
            q.pop();
            st.insert(f);
            if(mp.find(f) != mp.end())
                q.push(mp[f]);
        }
        for(int i = 0; i < v.size(); i++) {
            if(st.count(v[i]))
                return v[i];
        }
        return "";
    }
};
