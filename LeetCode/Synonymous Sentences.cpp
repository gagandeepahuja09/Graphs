class Solution {
public:
    unordered_set<string> vis;
    vector<vector<string>> vs;
    vector<string> v;
    vector<string> ret;
    void dfs(string temp, unordered_map<string, vector<string>>& mp, vector<string>& v) {
        if(vis.count(temp))
            return;
        vis.insert(temp);
        for(int i = 0; i < mp[temp].size(); i++) {
            dfs(mp[temp][i], mp, v);
        }
        vis.erase(temp);
        v.push_back(temp);
    }
    
    void findWords(string text, unordered_map<string, vector<string>>& mp, string s) {
        string temp = "";
        for(int i = 0; i < text.size(); i++) {
            if(text[i] == ' ' || i == text.size() - 1) {
               v.clear();
               if(i == text.size() - 1)
                   temp += text[i];
                dfs(temp, mp, v);
                vs.push_back(v);
                temp = "";
            }
            else
                temp += text[i];
        }
    }
    
    void doo(string s, vector<vector<string>>& vs, int i) {
        if(i == vs.size()) {
            s.pop_back();
            ret.push_back(s);
            return;
        }
        for(int j = 0; j < vs[i].size(); j++) {
            doo(s + vs[i][j] + " ", vs, i + 1);
        }
    }
    
    vector<string> generateSentences(vector<vector<string>>& sy, string text) {
        unordered_map<string, vector<string>> mp;
        for(int i = 0; i < sy.size(); i++) {
            string s1 = sy[i][0], s2 = sy[i][1];
            mp[s1].push_back(s2);
            mp[s2].push_back(s1);
        }
        findWords(text, mp, "");
        doo("", vs, 0);
        sort(ret.begin(), ret.end());
        return ret;
    }
};
