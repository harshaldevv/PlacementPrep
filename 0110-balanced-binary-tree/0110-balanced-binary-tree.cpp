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
    int helper(TreeNode* root){
        if(!root){
            return 0;
        }
        queue<TreeNode*> q;
        q.push(root);
        
        int h = 0;
        
        while(!q.empty()){
            int sz = q.size();
            while(sz--){
                auto front = q.front();
                q.pop();
                
                if(front->left){
                    q.push(front->left);
                }
                
                if(front->right){
                    q.push(front->right);
                }
                
            }
            
            h++;
        }
        
        return h;
    }
    bool isBalanced(TreeNode* root) {
        
        if(!root){
            return true;
        }
        
        if(!root->left && !root->right){
            return true;
        }
        
        int leftH = helper(root->left);
        int rightH = helper(root->right);
        
        return abs(leftH - rightH) <= 1 && isBalanced(root->left) && isBalanced(root->right);
        
    }
};