void dfs(int i,int n,int m,vector<int> &rec) {
    if(i > m) {
        return;
    }
    if(i <= m && i >= n)
        rec.push_back(i);
    int r = i % 10;
    if(r == 0)
        dfs(i * 10 + (r + 1), n, m, rec);
    if(r >= 1 && r <= 8) {
        dfs(i * 10 + (r - 1), n, m, rec);
        dfs(i * 10 + (r + 1), n, m, rec);
    }
    if(r == 9)
        dfs(i * 10 + (r - 1), n, m, rec);
}

vector<int> Solution::stepnum(int A, int B) {
    vector<int> ret;   
    for(int i = 1; i <= 9; i++) {
        dfs(i,A,B,ret);
    }
    if(A == 0)
        ret.push_back(0);
    sort(ret.begin(), ret.end());
    return ret;
}

