#include <bits/stdc++.h>
using namespace std;

#define int long long int
#define vi vector<int>
#define vvi vector<vi>
#define read(a)  for(int i = 0; i < n; i++) cin >> a[i];
#define print(a)  for(int i = 0; i < n; i++) cout << a[i] << " ";
#define pb push_back
#define ins insert
#define pql priority_queue<int>
#define pqs priority_queue<int, vi, greater<int>>
#define pqlv priority_queue<vi>
#define pqsv priority_queue<vi, vvi, greater<vi>>
#define endl '\n'

vector<set<int>> adj(26);
vector<bool> vis;

bool dfs(int u, int p) {
    if(vis[u])
        return false;
    vis[u] = 1;
    for(int v : adj[u]) {
        if(v == p)
            continue;
        if(!dfs(v, u))
            return false;
    }
    return true;
}

void dfs2(int u, int p) {
    cout << (char)(u + 'a');
    for(int v : adj[u]) {
        if(v == p)  continue;
        dfs2(v, u);
    }
}

signed main() {
    int t = 1;
    cin >> t;
    while(t--) {
        bool ans = true;
        string s;
        cin >> s;
        for(int i = 0; i < s.size() - 1; i++) {
            int u = s[i] - 'a', v = s[i + 1] - 'a';
            adj[u].ins(v);
            adj[v].ins(u);
        }
        vis.assign(26, 0);
        int root = -1;
        for(int i = 0; i < 26; i++) {
            if(adj[i].size() > 2) {
                ans = false;
            }
            if(adj[i].size() == 1) {
                root = i;
            }
        }
        if(!dfs(s[0] - 'a', -1)) {
            ans = false;
        }
        if(!ans)
            cout << "NO";
        else {
            cout << "YES" << endl;
            if(root != -1)
                dfs2(root, -1);
            for(int i = 0; i < 26; i++) {
                if(!adj[i].size())
                    cout << (char)(i + 'a');
            }
        }
        for(int i = 0; i < 26; i++) {
            adj[i].clear();
        }
        cout << endl;
    }
	return 0;
}
