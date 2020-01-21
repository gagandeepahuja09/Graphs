class Solution {
public:
    bool canCrackSafe(string& curr, unordered_set<string>& vis, int n, int k) {
        if(vis.size() == pow(k, n))
            return true;
        string lastdigs = curr.substr(curr.size() - n + 1);
        for(char ch = '0'; ch < '0' + k; ch++) {
            string newComb = lastdigs + ch;
            if(vis.count(newComb) == 0) {
                vis.insert(newComb);
                curr += ch;
                if(canCrackSafe(curr, vis, n, k))
                    return true;
                vis.erase(newComb);
                curr.pop_back();    
            }
        }
        return false;
    }
    
    string crackSafe(int n, int k) {
        string curr = string(n, '0');
        unordered_set<string> visited;
        visited.insert(curr);
        canCrackSafe(curr, visited, n, k);
        return curr;
    }
};
