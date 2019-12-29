class Solution {
public:
    void uni(int i, int j, vector<int>& parent) {
        int pi = find(i, parent);
        int pj = find(j, parent);
        parent[pi] = pj;
    }
    
    int find(int i, vector<int>& parent) {
        if(parent[i] != i) {
            parent[i] = find(parent[i], parent);
        }
        return parent[i];
    }
    
    vector<vector<string>> accountsMerge(vector<vector<string>>& acs) {
        unordered_map<string, int> mp;
        int n = acs.size();
        vector<pair<string, set<string>>> st(n);
        vector<int> parent(n);
        for(int i = 0; i < n; i++)
            parent[i] = i;
        for(int j = 0; j < n; j++) {
            for(int i = 1; i < acs[j].size(); i++) {
                if(mp.find(acs[j][i]) != mp.end()) {
                    uni(j, mp[acs[j][i]], parent);
                }
                else {
                    mp[acs[j][i]] = j;
                }
            }
        }
        for(int j = 0; j < n; j++) {
            int p = find(j, parent);
            st[p].first = acs[j][0];
            for(int i = 1; i < acs[j].size(); i++) {
                st[p].second.insert(acs[j][i]);
            }
        }
        vector<vector<string>> ret;
        for(int i = 0; i < n; i++) {
            if(st[i].first.size()) {
                vector<string> v(st[i].second.begin(), st[i].second.end());
                v.insert(v.begin(), st[i].first);
                ret.push_back(v);
            }
        }
        return ret;
    }
};
