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
    
    int helper(TreeNode* root){
        if(!root){
            return 0;
        }
        
        int left = helper(root->left);
        int right = helper(root->right);
        int diff = abs(left - right);
        
        if(left == -1 || right == -1 || diff > 1 ){
            return -1;
        }
        
        return 1 + max(left, right);
        
    }
    
    bool isBalanced(TreeNode* root) {
        
        // 0 is height of null tree
        // -1 represents NOT A BALANCED TREE
        return helper(root) != -1;
        
    }
};