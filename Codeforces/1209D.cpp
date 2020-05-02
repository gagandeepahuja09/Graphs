#include <bits/stdc++.h>
using namespace std;

#define int long long int

vector<int> par;

int find(int u) {
    if(par[u] == u)
        return u;
    return par[u] = find(par[u]);
}

signed main() {
    int t = 1;
    // cin >> t;
    while(t--) {
        int n, k;
        cin >> n >> k;
        par.resize(n + 1);
        for(int i = 1; i <= n; i++)
            par[i] = i;
        int ans = 0;
        for(int i = 0; i < k; i++) {
            int x, y;
            cin >> x >> y;
            x = find(x); y = find(y);
            if(x == y)
                ans++;
            else
                par[x] = y;
        }
        cout << ans << endl;
    }
	return 0;
}
