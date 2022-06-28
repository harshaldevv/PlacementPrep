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
    
    int l;
    
    int solve(TreeNode* root){
        if(root == nullptr){
            return 0;
        }
        
        int left = solve(root->left);
        
        int right = solve(root->right);
        
        if(root->left && root->left->val != root->val){
            left = 0;
        }
        if(root->right && root->right->val != root->val){
            right = 0;
        }
        
        l = max(l, left+right);
        
        return 1+ max(left, right);
        
        
        
        
        
    }
    int longestUnivaluePath(TreeNode* root) {
        l = 0;
        
        solve(root);
        
        
        return l;
        
        // Code which resolved which doubt  of what to do before l = max() wali line
        // https://leetcode.com/problems/longest-univalue-path/discuss/108152/Simple-C%2B%2B-DFS
        
    }
};