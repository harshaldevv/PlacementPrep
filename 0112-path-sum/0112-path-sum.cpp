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
    
    bool solve(TreeNode* root, int &tar, int s){
        if(root == nullptr){
            return false;
        }
        
        s += root->val;
        
        // cout << s << endl;
    
        if(!root->left && !root->right){
            if(s == tar){
                return true;
            }
        }
        
        return (solve(root->left, tar, s) || solve(root->right, tar, s));
    }
    bool hasPathSum(TreeNode* root, int tar) {
        int s = 0;
        return solve(root, tar, s);
        
    }
};