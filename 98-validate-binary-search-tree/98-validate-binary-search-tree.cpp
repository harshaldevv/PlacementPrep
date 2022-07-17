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
struct Triplet{
    int leftMax;
    int rightMin;
    bool isBst;
    
    Triplet(int x, int y, bool ans){
        leftMax = x;
        rightMin = y;
        isBst = ans;
    }
    
};

class Solution {
public:
    bool helper(TreeNode *root, long long smol, long long large){
        if(root == nullptr){
            return true;
        }
        
        
        if(smol >= root->val || large <= root->val){
            return false;
        }
        
        bool left = helper(root->left, smol, root->val);
        bool right = helper(root->right, root->val, large);
        
        return left &&right;
    }
    
    
    
    
    bool isValidBST(TreeNode* root) {
        
        // Brute Way --> For a BST, the inorder of BST is always sorted
        // therefore we do inorder traversal now, and store the values in an array
        // Then we chck if it is sorted or not. If it is sorted, we return true,
        // else we return false 
        // How we check if the array is sorted --> we iteratre the array, 
        // if we nums[i-1] < nums[i] for all the indexes we return true, else we return false
        
        // TC - O(n), SC - O(n)
        
        // Now we'll optimize on the space
        //return checker(root).isBst;
        
        
        // range of values se check kro
        // TC - O(n), SC - O(1)
         return helper(root, LLONG_MIN, LLONG_MAX);
        
    }
};