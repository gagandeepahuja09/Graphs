/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
TreeNode* Solution::sortedListToBST(ListNode* A) {
    if(!A)
        return NULL;
    if(!A -> next)
        return new TreeNode(A -> val);
    ListNode *prev = NULL, *slow = A, *fast = A;
    while(fast && fast -> next) {
        prev = slow;
        slow = slow -> next;
        fast = fast -> next -> next;
    }
    prev -> next = NULL;
    TreeNode* res = new TreeNode(slow -> val);
    res -> left = sortedListToBST(A);
    res -> right = sortedListToBST(slow -> next);
    return res;
}

