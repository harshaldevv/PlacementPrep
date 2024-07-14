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
    
    TreeNode* first = nullptr;
    TreeNode* second = nullptr;
    TreeNode* prev = nullptr;
    vector<int> ans;
    void inorder(TreeNode* root){
        if(!root){
            return ;
        }
                
        inorder(root->left);
        

        if(first == nullptr && prev && prev->val >= root->val){
            //first violation
            first = prev;
        }
        
        if(first != nullptr && prev && prev->val >= root->val){
            //second violation
            second = root;
        }
        
        
        prev = root;

        inorder(root->right);
        
        
        return ;
    }
    
    
    void recoverTree(TreeNode* root) {
        
        inorder(root);
        
        swap(first->val, second->val);
        
    }
};