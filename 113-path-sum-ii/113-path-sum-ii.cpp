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
    vector<vector<int>> ans;
    void helper(TreeNode *root, vector<int> &nums, int sum, int target){
        if(root == nullptr){
            return ;
        }
        sum+=root->val;
        nums.push_back(root->val);
        if(!root->left && !root->right && sum == target){
            // we found our targetSum 
            ans.push_back(nums);
            
            // return ;
            
            // In question wheer we need to  find "all" paths, dont return after you've met your condition
            
            // let it run and it will be eventually handled.
            
            // see the 2 submission of this problem and you'll realise what im talking about
        }
        helper(root->left, nums, sum, target);
        helper(root->right, nums, sum, target);
        nums.pop_back();
        return ;
    }
    vector<vector<int>> pathSum(TreeNode* root, int target) {
        ans.clear();
        
        if(root == nullptr){
            return ans;
        }
        
        int sum = 0;
        vector<int> nums;
        helper(root, nums, sum, target);
        return ans;
    }
};