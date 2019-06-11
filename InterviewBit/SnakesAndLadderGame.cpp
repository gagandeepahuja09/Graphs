int Solution::solve(int A, vector<int> &B, vector<int> &C) {
    queue<pair<int, int>> q;
    int mp[A + 1];
    memset(mp, 0, sizeof mp);
    for(int i = 0; i < B.size(); i++) {
        mp[B[i]] = C[i];
    }
    q.push({ 1, 0 });
    bool vis[A + 1];
    memset(vis, false, sizeof vis);
    vis[1] = true;
    while(!q.empty()) {
        pair<int, int> p = q.front();
        q.pop();
        if(p.first == A) {
            return p.second;
        }
        int t = p.first;
        if(t > A)
            break;
        vis[t] = 1;
        for(int i = t + 1; i <= t + 6 && i <= A; i++) {
            int num = i;
            if(mp[i])
                num = mp[i];
            if(!vis[num])  
                q.push({ num, p.second + 1 });    
        }
    }
    return 0;
}

