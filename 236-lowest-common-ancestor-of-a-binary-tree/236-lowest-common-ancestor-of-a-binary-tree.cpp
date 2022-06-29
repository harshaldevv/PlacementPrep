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
    TreeNode* solve(TreeNode* root, TreeNode* p, TreeNode* q){
        if(root == nullptr){
            return nullptr;
        }
        
        if(root == p){
            return p;
        }
        if(root == q){
            return q;
        }
        
        TreeNode *left = solve(root->left, p, q);
        TreeNode *right = solve(root->right, p, q);
        
        if(left == nullptr && right != nullptr ){
            return right;
        }
        else if(left != nullptr && right == nullptr){
            return left;
        }
        else{
            // dono null nahi hai toh
            return root;
        }
        
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        
        // recursive (dfs) traversal
       if(root == nullptr || root == p || root == q){
           return root;
       }
        
        TreeNode *left = lowestCommonAncestor(root->left, p, q);
        TreeNode *right = lowestCommonAncestor(root->right, p, q);
        
        if(!left && !right){
            // leaf node --> return null
            return nullptr;
        }
        
        if(!left && right ){
            return right;
        }
        else if(!right && left){
            return left;
        }
        else{
            return root;
        }
        
        
        
    }
};