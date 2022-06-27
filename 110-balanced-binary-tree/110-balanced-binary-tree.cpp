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
    int height2(TreeNode *root){
        if(root == nullptr){
            return 0;
        }
        
        int left = height2(root->left);
        if(left == -1){
            return -1;
        }
        
        int right = height2(root->right);
        if(right == -1){
            return -1;
        }
        
        if(abs(right - left) > 1){
            return -1;
        }
        
        return max(left, right) +1;
        
    }
    bool isBalanced(TreeNode* root) {
        if(height2(root) == -1){
            //unbalanced subtree mil gaya kahi
            return false;
        }
        else{
            return true;
        }
    }
};