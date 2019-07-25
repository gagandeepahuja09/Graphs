// Seg. Fault
/*string Solution::multiple(int A) {
    int st[A + 1];
    memset(st, 0, sizeof st);
    queue<int> q;
    q.push(1);
    while(!q.empty()) {
        int f = q.front();
        q.pop();
        int rem = f % A;
        if(rem == 0)
            return to_string(f);
        if(!st[rem]) {
            q.push(f * 10);
            q.push(f * 10 + 1);
        }
        st[rem] = 1;
    }
    return "";
}
*/

string Solution::multiple(int A) {
    if(!A)
        return "0";
    queue<int> q;
    int val[A + 1], par[A + 1], flag[A + 1];
    memset(val, -1, sizeof val);
    memset(par, -1, sizeof par);
    memset(flag, 0, sizeof flag);
    q.push(1 % A);
    val[1 % A] = flag[1 % A] = 1;
    while(!q.empty()) {
        int t = q.front();
        q.pop();
        if(!t) {
            string ret;
            while(t != -1) {
                ret = (char)(val[t] + '0') + ret;
                t = par[t];
            }
            return ret;
        }
        int t0 = (t * 10) % A;
        int t1 = (t * 10 + 1) % A;
        if(!flag[t0]) {
            flag[t0] = 1;
            par[t0] = t;
            val[t0] = 0;
            q.push(t0);
        }
        if(!flag[t1]) {
            flag[t1] = 1;
            par[t1] = t;
            val[t1] = 1;
            q.push(t1);
        }
    }
}
