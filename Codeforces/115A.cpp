#include<bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<vector<int>> g(n + 1);
    vector<int> ind(n + 1, 0);
    for(int i = 0; i < n; i++) {
        int u;
        cin >> u;
        if(u != -1) {
            g[u].push_back(i + 1);
            ind[i + 1]++;
        }
    }
    queue<int> q;
    int ans = 0;
    for(int i = 1; i <= n; i++) {
        if(ind[i] == 0) {
            q.push(i);
        }
    }
    while(!q.empty()) {
        int sz = q.size();
        ans++;
        for(int i = 0; i < sz; i++) {
            int t = q.front();
            q.pop();
            ind[t]--;
            for(auto x : g[t]) {
                if(--ind[x] == 0) {
                    q.push(x);
                }
            }
        }
    }
    cout << ans << endl;
    return 0;
}
