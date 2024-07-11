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
    TreeNode* helper(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(!root){
            return nullptr;
        }
        
        if(root == p || root == q){
            return root;
        }
        
        TreeNode* lefty = helper(root->left, p, q);
        TreeNode* righty = helper(root->right, p, q);
        
        if(lefty && righty){
            return root;
        }
        else if(!lefty){
            return righty;
        }
        else{
            return lefty;;
        }
        
        
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        
        if(!root){
            return nullptr;
        }
        
        return helper(root, p, q);
        
    }
};