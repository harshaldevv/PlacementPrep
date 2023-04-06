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
    bool helper(TreeNode* root, int &target, int sum){
        if(!root){
            return false;
        }

        sum += root->val;
       
        if(sum == target ){
            if(!root->left && !root->right){
                return true;
            }
        }
        
        bool left = helper(root->left, target, sum);
        bool right = helper(root->right, target, sum);
        
        if(left || right){
            return true;
        }
        else{
            return false;
        }
        
        
    }
    bool hasPathSum(TreeNode* root, int target) {
        
        if(!root){
            return false;
        }
        
        int sum = 0;
        
        return helper(root, target, sum);
        
    }
};