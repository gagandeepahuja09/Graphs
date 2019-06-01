#include <bits/stdc++.h>
using namespace std;

#define ll long long int

ll c[100001];
bool vis[100001];
ll n, m, ans, mn;
vector<vector<ll>> v(100001);

void dfs(ll i) {
    vis[i] = true;
    mn = min(mn, c[i]);
    for(int j = 0; j < v[i].size(); j++) {
        if(!vis[v[i][j]]) {
            dfs(v[i][j]);
        }
    }
}

int main() {
    cin >> n >> m;
    memset(c, 0, sizeof c);
    for(int i = 0; i < n; i++) {
        cin >> c[i];
    }
    for(int i = 0; i < m; i++) {
        ll x, y;
        cin >> x >> y;
        x--;    y--;
        v[x].push_back(y);
        v[y].push_back(x);
    }
    ans = 0;
    memset(vis, 0, sizeof vis);
    for(int i = 0; i < n; i++) {
        if(!vis[i]) {
            mn = INT_MAX;
            dfs(i);
            ans += mn;
        }
    }
    cout << ans << endl;
    return 0;
}
