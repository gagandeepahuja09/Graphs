#include<bits/stdc++.h>
using namespace std;

#define ll long long int
#define MAX 150002

vector<int> g[MAX];
bool vis[MAX];

long double sum;
long double cnt;

void dfs(int u, ll& v, ll& e) {
if(vis[u])
    return;
vis[u] = 1;    
v++;
e += g[u].size();
for(auto x : g[u]) {
    dfs(x, v, e);    
}
}

int main() {
int n, m;
cin >> n >> m;
memset(vis, false, sizeof vis);
for(int i = 0; i < m; i++) {
    int a, b;
    cin >> a >> b;
    g[a].push_back(b);
    g[b].push_back(a);
}
for(int i = 1; i <= n; i++) {
    if(!vis[i]) {
        ll v = 0, e = 0;
        dfs(i, v, e);
        if(e != v * (v - 1)) {
            cout << "NO";
            return 0;
        }
    }
}
cout << "YES";
return 0;
}
