class Solution {
public:
    vector<int> numsSameConsecDiff(int N, int k) {
        queue<pair<int, int>> q;
        for(int i = 1; i <= 9; i++) {
            q.push({ i, 1});
        }
        vector<int> ret;
        if(N == 1) {
            vector<int> v;
            for(int i = 0; i <= 9; i++)
                v.push_back(i);
            return v;
        }
        while(!q.empty()) {
            pair<int, int> t = q.front();
            q.pop();
            int num = t.first;
            int dig = t.second;
            if(dig == N) {
                ret.insert(num);
            }
            else {
                int next = num % 10 + k;
                if(next >= 0 && next <= 9) {
                    q.push({ num * 10 + next, dig + 1});
                }
                next = num % 10 - k;
                if(next >= 0 && next <= 9 && k == 0) {
                    q.push({ num * 10 + next, dig + 1 });
                }
            }
        }
        return vector<int>(ret.begin(), ret.end());
    }
};
