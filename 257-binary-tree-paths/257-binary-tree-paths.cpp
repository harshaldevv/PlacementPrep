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
    void helper(TreeNode *root, vector<string> &ans, string p){
        if(root->left == nullptr && root->right == nullptr){
            ans.push_back(p);
        }
        
        if(root->left){
            helper(root->left, ans, p + "->" + to_string(root->left->val));
        }
        
        if(root->right){
            helper(root->right, ans, p + "->" + to_string(root->right->val));
        }
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> path;
        if(root == nullptr){
            return path;
        }
        
        helper(root, path, to_string(root->val));
        return path;
        
    }
};