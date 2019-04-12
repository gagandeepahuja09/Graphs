/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
vector<vector<int> > Solution::levelOrder(TreeNode* A) {
    vector<vector<int>> ret;
    queue<TreeNode*> q;
    q.push(A);
    while(!q.empty()) {
        int sz = q.size();
        vector<int> v;
        for(int i = 0; i < sz; i++) {
            TreeNode* t = q.front();
            v.push_back(t -> val);
            q.pop();
            if(t -> left)
                q.push(t -> left);
            if(t -> right)
                q.push(t -> right);
        }
        ret.push_back(v);
    }
    return ret;
}

