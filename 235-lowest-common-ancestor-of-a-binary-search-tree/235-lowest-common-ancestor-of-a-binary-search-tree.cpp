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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        
        // Using the property of BST that left of root <= root < right of root
        
        if(root == nullptr){
            return nullptr;
        }
        
        if(root->val > p->val && root->val > q->val){
            // see example 2
            // answer lies in left half of root
            return lowestCommonAncestor(root->left, p, q);
        }
        else if(root->val < p->val && root->val < q->val){
            // answer lies in right half of root
            return lowestCommonAncestor(root->right, p, q);
        }
        else{
            // see example 1
            // both p and q lies in either side of the root,
            // therefore ans = root
            return root;
        }
        
        // TC -> O(logN)
        // SC -> O(logN) --> recursive stack
        
    }
};