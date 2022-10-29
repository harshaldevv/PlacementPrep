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
        
        int left = helper(root->left);
        int right = helper(root->right);
        int diff = abs(left - right);
        
        if(left == -1 || right == -1 || diff > 1 ){
            return -1;
        }
        
        return 1 + max(left, right);
        
        // This function basically counts the height of the tree 
        // incase the tree breaks the "balanced" nature of itself
        // we return -1 to specially indicate that the balanced nature has 
        // been broken and this is not a balanced tree 
        // and no further computations should be done
        
    }
    
    bool isBalanced(TreeNode* root) {
        
        // 0 is height of null tree
        // -1 represents NOT A BALANCED TREE
        
        return helper(root) != -1;
        
        /*
        The checkBalance function actually calculates the height of the given tree. 
        And while calculating the height it just compares the height of left and right subtree. 
        If it comes greater than 1 then the answer is marked as false, 
        because it is not balanced. 
        The return thing is because it is returning the height of the tree.
        */
        
    }
};