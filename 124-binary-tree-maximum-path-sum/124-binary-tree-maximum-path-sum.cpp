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
    int helper(TreeNode* root, int &maxSum){
        if(root == nullptr){
            return 0;
        }
        
        int left = helper(root->left, maxSum);
        int right = helper(root->right, maxSum);
        
        int mereKoLekeSum = max(root->val, root->val + max(left ,right)) ;
        
        int totalPathSum = max(mereKoLekeSum, root->val + left + right );
        
        maxSum = max(maxSum, totalPathSum );
        
        return mereKoLekeSum ;
        
    }
    int maxPathSum(TreeNode* root) {
        
        int maxSum = INT_MIN;
        
        helper(root, maxSum);
        
        return maxSum;
        
    }
};