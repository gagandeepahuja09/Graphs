bool isAdjacent(string a, string b) {
    int cnt = 0;
    for(int i=0; i<a.size(); i++) {
        if(a[i] != b[i])
            cnt++;
    }
    if(cnt == 1)
        return true;
    return false;    
}

int Solution::ladderLength(string start, string end, vector<string> &dictV) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    if(start == end)
        return 1;
    queue<pair<string, int>> q;
    q.push({ start, 1 });
    for(int i=0; i<dictV.size(); i++) {
        if(dictV[i] == start) {
            dictV.erase(dictV.begin() + i);
            i--;
        }
    }
    unordered_set<string> vis;
    vis.insert(start);
    while(!q.empty()) {
        pair<string, int> top = q.front();
        string s = top.first;
        q.pop();
        if(s == end) {
            return top.second;
        }
        for(int i=0; i<dictV.size(); i++) {
            if(isAdjacent(s, dictV[i])) {
                q.push({ dictV[i], top.second + 1 });
                dictV.erase(dictV.begin() + i);
                i--;
            }
        }
    }
    return 0;
}

