/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    bool helper(TreeNode *root, long long smol, long long large){
        if(root == nullptr){
            return true;
        }
        
        // if(root->left == nullptr && root->right == nullptr){
            // leaf node is always a BST
            // return true;
        // }
        
        if(smol >= root->val || large <= root->val){
            return false;
        }
        
        bool left = helper(root->left, smol, root->val);
        bool right = helper(root->right, root->val, large);
        
        return left &&right;
    }
    bool isValidBST(TreeNode* root) {
        
        // range of values se check kro
        return helper(root, LLONG_MIN, LLONG_MAX);
        
    }
};