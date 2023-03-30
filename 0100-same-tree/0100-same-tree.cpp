/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        
        //hci research 
        // If both trees are NULL, then they are the same
        if (p == NULL && q == NULL) {
            return true;
        }
        
        // If one of the trees is NULL, but not the other, then they are not the same
        if (p == NULL || q == NULL) {
            return false;
        }
        
        // If the root nodes of both trees have different values, then they are not the same
        if (p->val != q->val) {
            return false;
        }
        
        // Recursively check if the left subtrees and right subtrees are the same
        return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
    }
};
