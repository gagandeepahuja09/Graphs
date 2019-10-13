#include<bits/stdc++.h>
using namespace std;

int main()  {
    int n;
    cin >> n;
    vector<string> v(n);
    queue<int> q;
    for(int i = 0; i < n; i++)
        cin >> v[i];
    vector<vector<int>> adj(26);
    vector<int> ind(26, 0);
    for(int i = 0; i < n - 1; i++) {
        string s1 = v[i], s2 = v[i + 1];
        for(int j = 0; j < s1.size() && j < s2.size(); j++) {
            if(s1[j] == s2[j])
                continue;
            adj[s1[i] - 'a'].push_back(s2[i] - 'a');
            ind[s1[i] - 'a']++;
        }
    }
    bool flag = true;
    for(int i = 0; i < 26; i++) {
        if(ind[i] == 0) {
            q.push(i);
        }
    }
    while(!q.empty()) {
        int f = q.front();
        q.pop();
        ind[f]--;
        cout << char(f + 'a');
        for(int i = 0; i < adj[f].size(); i++) {
            if(--ind[adj[f][i]] == 0)
                q.push(adj[f][i]);
        }
    }
    for(int i = 0; i < 26; i++)
        if(ind[i] > 0)
            flag = false;
    if(!flag)
        cout << "Invalid";
    return 0;
}
