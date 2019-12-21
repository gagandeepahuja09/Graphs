class Solution {
public:
    int N;
    vector<int> ret;
    void f(int n) {
        if(n > N)
            return;
        ret.push_back(n);
        for(int i = 0; i <= 9; i++) {
            f(n * 10 + i);
        }
    }
    
    vector<int> lexicalOrder(int n) {
        N = n;
        for(int i = 1; i <= 9; i++) {
            f(i);
        }
        return ret;
    }
};
