bool hasdiff(string s1, string s2) {
    int cnt = 0;
    for(int i = 0; i < s1.size(); i++) {
        if(s1[i] != s2[i])
            cnt++;
    }
    return (cnt == 1);
}

int Solution::ladderLength(string start, string end, vector<string> &dictV) {
    queue<pair<string, int>> q;
    if(start == end)
        return 1;
    q.push({ start, 1 });
    int cnt = 1;
    for(int i=0; i<dictV.size(); i++) {
        if(dictV[i] == start) {
            dictV.erase(dictV.begin() + i);
            i--;
        }
    }
    while(!q.empty()) {
        pair<string, int> p = q.front();
        q.pop();
        if(hasdiff(p.first, end)) {
            return p.second + 1;
        }
        cnt++;
        for(int i = 0; i < dictV.size(); i++) {
            if(hasdiff(p.first, dictV[i])) {
                q.push({ dictV[i], p.second + 1 });
                dictV.erase(dictV.begin() + i);
                i--;
            }
        }
    }
    return 0;
}

