#include<bits/stdc++.h>
using namespace std;

#define ll long long int

void dfs(int a, vector<int>& x, vector<int>& y, vector<bool>& vis) {
    if(vis[a])
        return;
    vis[a] = 1;    
    for(int i = 0; i < x.size(); i++) {
        if((x[i] == x[a] || y[i] == y[a]) && !vis[i]) {
            dfs(i, x, y, vis);
        }
    }
}

int main() {
    int n, ans = 0;
    cin >> n;
    vector<int> x(n), y(n);
    vector<bool> vis(n, false);
    for(int i = 0; i < n; i++) {
        cin >> x[i] >> y[i];
    }
    for(int i = 0; i < n; i++) {
        if(!vis[i]) {
            dfs(i, x, y, vis);
            ans++;
        }
    }
    cout << ans - 1 << endl;
}
