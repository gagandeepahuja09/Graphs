#include<bits/stdc++.h>
using namespace std;

#define ll long long int

int main() {
    int n, m;
    cin >> n >> m;
    unordered_set<int> st;
    for(int i = 1; i <= n; i++)
        st.insert(i);
    for(int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        st.erase(a); st.erase(b);
    }
    cout << n - 1 << endl;
    int t = *st.begin();
    for(int i = 1; i <= n; i++) {
        if(i != t)
            cout << t << " " << i << endl;
    }
}
