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
    void helper(TreeNode* root, string s, vector<string> &ans){
        if(!root){
            return ;
        }
        
        if(root->left == nullptr && root->right == nullptr){
            // leaf node
            s += to_string(root->val);
            ans.push_back(s);
            return;
        }
    
        s += to_string(root->val);
        s += "->";
        helper(root->left, s , ans);    
        helper(root->right, s , ans);
        
        return;
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        
        string s = "";
        vector<string> ans;
        helper(root, s, ans);
        return ans;
        
    }
};