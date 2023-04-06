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
    void helper(TreeNode* root, int sum, int &target, vector<int> temp, vector<vector<int>> &ans){
        if(!root){
            return ;
        }
        
        sum += root->val;
        temp.push_back(root->val);
        
        if(sum == target && !root->left && !root->right){
            ans.push_back(temp);
        }
        
        // go left
        helper(root->left, sum, target, temp, ans);
        
        // go right
        helper(root->right, sum, target, temp, ans);
        
        
        temp.pop_back();
    }
    vector<vector<int>> pathSum(TreeNode* root, int target) {
        
        vector<vector<int>> ans;
        
        vector<int> temp;
        int sum = 0;
        helper(root, sum, target, temp, ans);
        
        return ans;
        
    }
};