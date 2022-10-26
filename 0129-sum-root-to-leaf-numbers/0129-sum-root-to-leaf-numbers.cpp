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
    
    int solve(TreeNode* root, int s){
        
        if(root == nullptr){
            return 0;
        }
        
        
        s = s*10 + root->val;
        
        if(!root->left && !root->right){
            return s;
        }
        
        return solve( root->left , s ) + solve( root->right, s );
        
        
        // return s;
        
    }
    
    int sumNumbers(TreeNode* root) {
        
        if(root == nullptr){
            return 0;
        }
        
        int s = 0;
         return solve(root, s);
        
        // return s;
        
    }
};