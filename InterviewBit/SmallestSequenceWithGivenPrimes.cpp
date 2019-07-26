vector<int> Solution::solve(int p1, int p2, int p3, int K) {
    vector<int> ret;
    int i = 0, j = 0, k = 0; 
    ret.push_back(1);
    while(K--) {
        ret.push_back(min(ret[i] * p1, min(ret[j] * p2, ret[k] * p3)));
        if(ret.back() == ret[i] * p1) i++;
        if(ret.back() == ret[j] * p2) j++;
        if(ret.back() == ret[k] * p3) k++;
    }
    ret.erase(ret.begin());
    return ret;
}

