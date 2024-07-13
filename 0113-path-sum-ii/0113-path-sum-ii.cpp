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
    void f(TreeNode* root, int target, int sum, vector<int> temp, vector<vector<int>> &ans){
        if(!root){
            return ;
        }
        sum += root->val;
        if(root && !root->left && !root->right){
            // child node
            if(sum == target){
                temp.push_back(root->val);
                ans.push_back(temp);
            }
            return;
        }
    
        temp.push_back(root->val);
        f(root->left, target, sum, temp, ans);
        
        f(root->right, target, sum, temp, ans);
        temp.pop_back();
        
        return ;
        
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> ans;
        if(!root){
            return ans;
        }
        vector<int> temp;
        int sum = 0;
        f(root, targetSum, sum, temp, ans);
        return ans;
        
    }
};