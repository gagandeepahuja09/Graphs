class Solution {
public:
    static bool cmp(string s1, string s2) {
        if(s1.size() == s2.size())
            return s1 < s2;
        return s1.size() < s2.size();
    }
    
    int diff(string s, string t) {
        int i = 0, j = 0;
        while(i < s.size() && j < t.size()) {
            if(s[i] == t[j])
                i++, j++;
            else
                i++;
        }
        return j == t.size();
    }
    
    int longestStrChain(vector<string>& w) {
        queue<pair<pair<string, int>, int>> q;
        sort(w.begin(), w.end(), cmp);
        for(int i = 0; i < w.size(); i++) {
            q.push({{ w[i], i }, 1});
        }
        int mx = 0;
        while(!q.empty()) {
            auto f = q.front();
            string s = f.first.first;
            int idx = f.first.second;
            q.pop();
            int sz = s.size();
            mx = max(mx, f.second);
            for(int i = idx + 1; i < w.size(); i++) {
                if(w[i].size() - s.size() == 1 && diff(w[i], s)) {
                    q.push({ { w[i], i }, 1 + f.second });    
                }
            }
        }
        return mx;
    }
};
