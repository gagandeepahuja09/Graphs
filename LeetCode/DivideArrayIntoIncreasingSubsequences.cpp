class Solution {
public:
bool canDivideIntoSubsequences(vector<int>& nums, int K) {
    /* queue<pair<int, int>> q;
    q.push({ nums[0], 1 });
    for(int i = 1; i < nums.size(); i++) {
        if(nums[i] > q.front().first) {
            int t = q.front().second;
            q.pop();
            q.push({ nums[i], t + 1 });
        }
        else {
            q.push({ nums[i], 1 });
        }
    }
    while(!q.empty()) {
        if(q.front().second < K)
            return false;
        q.pop();
    }
    return true; */
    int cnt = 1, mx = 1;
    for(int i = 1; i < nums.size(); i++) {
        if(nums[i] == nums[i - 1])
            cnt++;
        else
            cnt = 1;
        mx = max(mx, cnt);
    }
    return (nums.size() >= mx * K);
}
};
