class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        set<string> st;
        queue<pair<string, int>> q;
        set<string> vis;
        for (string s : wordList) {
            st.insert(s);
        }
        q.push({ beginWord, 1 });
        // Two options, depends on wordList length and wordLength
        while (!q.empty()) {
            string currWord = q.front().first;
            int steps = q.front().second;
            q.pop();
            if (currWord == endWord) {
                return steps;
            }
            if (vis.find(currWord) != vis.end()) {
                continue;
            }
            vis.insert(currWord);
            // 100 * 26
            for (int j = 0; j < currWord.size(); j++) {
                for (int k = 0; k < 26; k++) {
                    char changeChar = k + 'a';
                    // cout << changeChar << " " << temp << endl;
                    if (changeChar == currWord[j]) {
                        continue;
                    }
                    string temp = currWord;
                    temp[j] = changeChar;
                    if (st.find(temp) != st.end()) {
                        q.push({ temp, steps + 1 });
                    }
                }
            }
        }
        return 0;
    }
};
