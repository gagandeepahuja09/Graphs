class Solution {
public:
    bool pyramidPossible(string bottom, unordered_map<string, vector<string>>& mp, int i, string upper) {
        if(bottom.size() == 1)
            return true;
        if(i == bottom.size() - 1)
            return pyramidPossible(upper, mp, 0, "");
        for(string s : mp[bottom.substr(i, 2)])
            if(pyramidPossible(bottom, mp, i + 1, upper + s))
                return true;
        return false;
    }
    
    bool pyramidTransition(string bottom, vector<string>& allowed) {
        unordered_map<string, vector<string>> mp;
        for(string s : allowed) {
            mp[s.substr(0, 2)].push_back(s.substr(2));
        }
        return pyramidPossible(bottom, mp, 0, "");
    }
};
