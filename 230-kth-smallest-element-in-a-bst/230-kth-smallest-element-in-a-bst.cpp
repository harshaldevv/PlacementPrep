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
    int ans;
    int count = 0;
    void inorder(TreeNode *root, int k){
        
        if(root == nullptr){
            return ;
        }
        
        // left, root, right
        
        inorder(root->left, k);
        
        count++;
        if(count == k){
            ans = root->val;
            return ;
        }
        
        inorder(root->right, k);
        
        return ;
    }
    int kthSmallest(TreeNode* root, int k) {
        
        // For kth smallest in BST, use normal inorder
        // inorder --> left, root, right
        // use the counter thing then
        
        
        inorder(root, k);
        
        return ans;
        
        // For Kth LARGEST, use MODIFIED INORDER
        // Modified inorder -> right, root, left
        // use the counter thing then, similar to how we it in this ques
        
        
        
    }
};