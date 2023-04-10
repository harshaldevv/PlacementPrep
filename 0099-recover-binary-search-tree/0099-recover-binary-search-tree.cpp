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
    TreeNode* first = NULL;
    TreeNode* second = NULL;
    TreeNode* prev = new TreeNode(INT_MIN);
    
    void inorder(TreeNode* root){
        if(!root){
            return ;
        }
        
        inorder(root->left);
        
        // do work here
        
        if(first == NULL && root->val < prev->val){
            //first violation
            first = prev;
        }
        
        if(first != NULL && root->val < prev->val){
            //second violation found
            second = root;
        }
        
        prev = root;
        

        inorder(root->right);
        
        return ;
    }
    void recoverTree(TreeNode* root) {
        first= NULL;
        second = NULL;
        inorder(root);
        
        swap(first->val, second->val);
        
        
        return ;
        
    }
};