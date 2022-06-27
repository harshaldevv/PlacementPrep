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
        
        int leftHeight = height(root->left);
        int rightHeight = height(root->right);
        
        return max(leftHeight,rightHeight ) +1;
    }
    
    int height2(TreeNode *root, int &dia){
        if(root== nullptr){
            return 0;
        }
        
        int lh = height2(root->left, dia);
        int rh = height2(root->right, dia);
        
        dia = max(dia, lh+rh);
        
        return 1 + max(lh,rh);
    }
    int diameterOfBinaryTree(TreeNode* root) {
        
        if(root == nullptr){
            return 0;
        }
        
//         int left = height(root->left);
//         int right = height(root->right);
        
//         return left+right;
        
        
        //Above approach fails at 100/104 th test case--> gives WA
        // cuz diameter "path" may or "may not" "pass" through the "root".
        
        
        
        // DOing second approach
        int diameter = 0;
        height2(root, diameter);
        return diameter;
        
    }
};