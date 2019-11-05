#include<bits/stdc++.h>
using namespace std;

#define ll long long int
#define MOD 1000000007
#define MAX 200005

ll n, q;

int main() {
// ll t;
// cin >> t; while(t--) {
ll n, m;
cin >> n >> m;
vector<ll> v(n);
priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> pq;
for(int i = 0; i < n; i++) {
    cin >> v[i];
    pq.push({ v[i], i });
}
vector<set<ll>> adj(n);
for(int i = 0; i < m; i++) {
    ll x, y;
    cin >> x >> y;
    x--; y--;
    adj[x].insert(y);
    adj[y].insert(x);
} 
ll ans = 0;
while(!pq.empty()) {
    auto p = pq.top();
    ll val = p.first, u = p.second;
    pq.pop();
    ans += val * (adj[u].size());
    for(int i = 0; i < n; i++) {
        if(adj[i].find(u) != adj[i].end()) {
            adj[i].erase(u);
        }
    }
}
cout << ans << endl;
// }
}
