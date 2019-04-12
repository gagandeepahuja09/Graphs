void stepping(int val, int N, int M, vector<int>& v) {
    if(val >= N && val <= M) {
        v.push_back(val);
    }
    if(val > M)
        return;
    int rem = val % 10;
    if(rem == 0) {
        stepping(val * 10 + (rem + 1), N, M, v);    
    }
    else if(rem == 9) {
        stepping(val * 10 + (rem - 1), N, M, v);
    }
    else {
        stepping(val * 10 + (rem - 1), N, M, v);
        stepping(val * 10 + (rem + 1), N, M, v);
    }
}

vector<int> Solution::stepnum(int N, int M) {
    vector<int> v;
    for(int i = 1; i <= 9; i++) {
        stepping(i, N, M, v);
    }
    sort(v.begin(), v.end());
    return v;
}

