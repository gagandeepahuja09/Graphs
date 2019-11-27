class Solution {
public:
    int integerReplacement(int n) {
        queue<pair<int, int>> q;
        q.push({ 0, n });
        while(!q.empty()) {
            auto f = q.front();
            q.pop();
            int steps = f.first, val = f.second;
            if(val == 1) {
                return steps;
            }
            if(val % 2 == 0) {
                q.push({ steps + 1, val / 2 });
            }
            else {
                q.push({ steps + 1, (val - 1) });
                if(val == 2147483647)
                    q.push({ steps + 2, val / 2 + 1 });
                else
                    q.push({ steps + 1, (val + 1)  });
            }
        }
        return 0;
    }
};
