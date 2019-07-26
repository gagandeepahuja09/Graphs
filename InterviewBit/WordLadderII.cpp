bool adj(string s, string t) {
    int cnt = 0;
    for(int i = 0; i < s.size(); i++) {
        if(s[i] != t[i])
            cnt++;
    }
    return (cnt == 1);
}

vector<vector<string> > Solution::findLadders(string start, string end, vector<string> &dict) {
    sort(dict.begin(), dict.end());
    for(int i = 1; i < dict.size(); i++) {
        if(dict[i] == dict[i - 1]) {
            dict.erase(dict.begin() + i);
            i--;
        }
    }
    queue<vector<string>> q;
    q.push({ start });
    int level = -1;
    vector<vector<string>> ret;
    while(!q.empty()) {
        vector<string> t = q.front();
        q.pop();
        if(t.back() == end && (level == -1 || t.size() == level)) {
            ret.push_back(t);
            level = t.size();
        }
        else if(t.size() < level) {
            for(int i = 0; i < dict.size(); i++) {
                if(adj(dict[i], t.back()) && find(t.begin(), t.end(), dict[i]) == t.end()) {
                    vector<string> v = t;
                    v.push_back(dict[i]);
                    q.push(v);
                }
            }
        }
    }
    return ret;
}
