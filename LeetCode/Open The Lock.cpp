class Solution {
public:
    void pushQueue(unordered_set<string>& vis, string temp, unordered_set<string>& deads, queue<pair<string, int>>& q, int steps) {
        if(vis.find(temp) == vis.end()) {
            if(deads.find(temp) == deads.end()) {
                q.push({ temp, steps + 1 });
                vis.insert(temp);
            }
        }
    }
    
    int openLock(vector<string>& deadends, string target) {
        queue<pair<string, int>> q;
        unordered_set<string> deads(deadends.begin(), deadends.end());
        unordered_set<string> vis;
        string s = "0000";
        vis.insert(s);
        if(deads.count(s))
            return -1;
        q.push({ s, 0 });
        int sz = 0;
        while(!q.empty()) {
            auto f = q.front();
            q.pop();
            string curr = f.first;
            int steps = f.second;
            if(curr == target) {
                return steps;
            }
            for(int i = 0; i < curr.size(); i++) {
                string temp = curr;
                int num = temp[i] - '0';
                int up = (num + 1) % 10;
                int down = (num - 1 + 10) % 10;
                temp[i] = (up + '0');
                pushQueue(vis, temp, deads, q, steps);
                temp[i] = (down + '0');
                pushQueue(vis, temp, deads, q, steps);
            }
        }
        return -1;
    }
};
