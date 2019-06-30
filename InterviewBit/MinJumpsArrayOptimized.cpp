// BFS
/*

Min Jumps Array

Given an array of non-negative integers, you are initially positioned at the first index of the array.

Each element in the array represents your maximum jump length at that position.

Your goal is to reach the last index in the minimum number of jumps.

Example : Given array A = [2,3,1,1,4]

The minimum number of jumps to reach the last index is 2. (Jump 1 step from index 0 to 1, then 3 steps to the last index.)

If it is not possible to reach the end index, return -1.*/

int Solution::jump(vector<int> &A) {
    if(A.size() <= 1)
        return 0;
    int currMax = 0, level = 0, i = 0;
    while(i <= currMax) {
        int farthest = currMax;
        while(i <= currMax) {
            farthest = max(farthest, A[i] + i);
            if(farthest >= A.size() - 1)
                return level + 1;
            i++;
        }
        level++;
        currMax = farthest;
    }
    return -1;
}

