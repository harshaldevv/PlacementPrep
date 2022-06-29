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
    int countLeftHeight(TreeNode * root){
        if(root == nullptr){
            return 0;
        }
        // recursive way --> iterative way bhi likhunga, it wont take up stack space
        
        // return 1 + countLeftHeight(root->left); // keep going left
        
        int h = 0;
        while(root){
            h++;
            root = root->left;
        }
        
        return h;
        
    }
    
    int countRightHeight(TreeNode *root){
        if(root == nullptr){
            return 0;
        }
        // recursive way --> iterative way bhi likhunga, it wont take up stack space
        
        // return 1 + countRightHeight(root->right); // keep going right
        
        int h = 0;
        while(root){
            h++;
            root = root->right;
        }
        
        return h;
        
    }
    int countNodes(TreeNode* root) {
        if(root == nullptr){
            return 0;
        }
        
        int lh = countLeftHeight(root);
        int rh = countRightHeight(root);
        
        if(lh == rh){
            return (int)pow(2,lh) -1;
            
        }
        
        return 1 + countNodes(root->left) + countNodes(root->right);
        
        
    }
};