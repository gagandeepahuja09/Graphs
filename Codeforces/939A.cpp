#include<bits/stdc++.h>
using namespace std;

#define ll long long int

int main() {
    int n;
    cin >> n;
    bool ans = false;
    vector<int> v(n);
    for(int i = 0; i < n; i++) {
        cin >> v[i];
        v[i]--;
    }
    for(int i = 0; i < n; i++) {
        int t = 2;
        int num = v[i];
        while(t--) {
            num = v[num];
        }
        if(num == i)
            ans = true;
    }
    cout << ((ans == true) ? "YES" : "NO") << endl; 
}
