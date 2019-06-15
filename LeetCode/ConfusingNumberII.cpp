/* 1088. Confusing Number II

    User Accepted: 101
    User Tried: 247
    Total Accepted: 104
    Total Submissions: 576
    Difficulty: Hard

We can rotate digits by 180 degrees to form new digits. When 0, 1, 6, 8, 9 are rotated 180 degrees, they become 0, 1, 9, 8, 6 respectively. When 2, 3, 4, 5 and 7 are rotated 180 degrees, they become invalid.

A confusing number is a number that when rotated 180 degrees becomes a different number with each digit valid.(Note that the rotated number can be greater than the original number.)

Given a positive integer N, return the number of confusing numbers between 1 and N inclusive.

 

Example 1:

Input: 20
Output: 6
Explanation: 
The confusing numbers are [6,9,10,16,18,19].
6 converts to 9.
9 converts to 6.
10 converts to 01 which is just 1.
16 converts to 91.
18 converts to 81.
19 converts to 61.

Example 2:

Input: 100
Output: 19
Explanation: 
The confusing numbers are [6,9,10,16,18,19,60,61,66,68,80,81,86,89,90,91,98,99,100].

 

Note:

    1 <= N <= 10^9

*/

#define ll long long int

ll rotate(ll n) {
    // using vector instead of map avoided TLE
    vector<int> mp = {0, 1, -1, -1, -1, -1, 9, -1, 8, 6, -1 };
    mp[1] = 1;
    mp[0] = 0;
    mp[6] = 9;
    mp[8] = 8;
    mp[9] = 6;
    ll x = 0;
    while(n) {
        x = x * 10 + mp[n % 10];
        n /= 10;
    }
    return x;
}

class Solution {
public:
    int confusingNumberII(int N) {
        queue<ll> q;
        q.push(1);
        q.push(6);
        q.push(8);
        q.push(9);
        int cnt = 0;
        while(!q.empty()) {
            ll t = q.front();
            q.pop();
            if(t > N)
                break;
            if(t != rotate(t))
                cnt++;
            if(t == N)
                break;
            q.push(t * 10);
            q.push(t * 10 + 1);
            q.push(t * 10 + 6);
            q.push(t * 10 + 8);
            q.push(t * 10 + 9);
        }
        return cnt;
    }
};
