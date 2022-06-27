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
    
    int height(TreeNode *root){
        if(root == nullptr){
            return 0;
        }
        
        int left = height(root->left);
        int right = height(root->right);
        
        return max (left, right) +1;
    }
    
    bool isBalanced(TreeNode* root) {
        if(root == nullptr){
            return true;
        }
        
        int left = height(root->left);
        int right = height(root->right);
        // cout <<"left, right = " << left << ", " << right << endl;
        int diff = abs(right - left);
        // cout << "diff = " << diff << endl;
        
        if(diff > 1){
            return false;
        }
        
        bool leftcheck = isBalanced(root->left);
        bool rightcheck = isBalanced(root->right);
        
        if(leftcheck && rightcheck){
            return true;
        }
        else{
            return false;
        }
        
        
        /***
         a height-balanced binary tree is defined as:
         a binary tree in which the left and right subtrees of every node differ in height
         by no more than 1.
         
         AKA HEIGHT DIFF = ATMOST "1"
         
        ***/
        
    }
};