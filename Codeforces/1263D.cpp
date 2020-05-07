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

vector<int> parent(26);

int find(int u) {
    if(parent[u] == u)
        return u;
    return parent[u] = find(parent[u]);
}

signed main() {
    int t = 1;
    // cin >> t;
    while(t--) {
        for(int i = 0; i < 26; i++)
            parent[i] = i;
        int n;
        cin >> n;
        vector<int> c(26, 0);
        for(int i = 0; i < n; i++) {
            string s;
            cin >> s;
            for(int j = 0; j < s.size(); j++) {
                c[s[j] - 'a']++;
                for(int k = j + 1; k < s.size(); k++) {
                    int u = s[j] - 'a', v = s[k] - 'a';
                    u = find(u), v = find(v);
                    if(u != v) {
                        parent[u] = v;
                    }
                }
            }
        }
        int ans = 0;
        for(int i = 0; i < 26; i++) {
            if(c[i] && parent[i] == i) {
                // cout << i << " ";
                ans++;
            }
        }
        // cout << parent[3] " " << c[3] << " ";
        cout << ans << endl;
    }
	return 0;
}
