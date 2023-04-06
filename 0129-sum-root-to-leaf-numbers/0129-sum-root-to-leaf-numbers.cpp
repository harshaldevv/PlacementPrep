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
    
    int solve(TreeNode* root, int sum){
        if(!root){
            return 0;
        }
        

        sum *= 10;
        sum += root->val;
        
        if(root->left == NULL && root->right == NULL){
            return sum;
        }
        
        int left = solve(root->left, sum);
        int right = solve(root->right, sum);
        
        return left + right;
        
        
    }
    int sumNumbers(TreeNode* root) {
        
        if(!root){
            return 0;
        }
        int ans = 0;
        return solve(root, ans);
        
    }
};