bool isValid(string s) {
    stack<char> stk;
    for(int i = 0; i < s.size(); i++) {
        if(s[i] == '(')
            stk.push(s[i]);
        else if(s[i] == ')') {
            if(stk.empty())
                return false;
            stk.pop();    
        }    
    }
    return stk.empty();
}

vector<string> Solution::solve(string A) {
    queue<string> q;
    unordered_set<string> st;
    q.push(A);
    vector<string> ret;
    while(!q.empty()) {
        string curr = q.front();
        q.pop();
        if(st.count(curr))
            continue;
        st.insert(curr);
        if(isValid(curr)) {
            ret.push_back(curr);
        }
        else if(ret.empty()) {
            for(int i = 0; i < curr.size(); i++) {
                if(curr[i] == ')' || curr[i] == '(')
                    q.push(curr.substr(0, i) + curr.substr(i + 1));
            }
        }
    }
    return ret;
}

