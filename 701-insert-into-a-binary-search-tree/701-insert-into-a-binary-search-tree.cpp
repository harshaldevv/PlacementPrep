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
    TreeNode* insertIntoBST(TreeNode* ROOT, int val) {
        if(ROOT== nullptr){
            TreeNode* temp = new TreeNode(val);
            return temp;
        }
        TreeNode *prev;
        TreeNode* root = ROOT;
        while(root){
            if(root->val > val){
                // go left
                prev = root;
                root = root->left;
            }
            else{
                prev = root;
                root = root->right;
            }
        }
        
        TreeNode *temp = new TreeNode(val);
        if(prev->val > val){
            //insert in left
            // prev = 30  --> acc too example 2
            // val = 25   --> acc too example 2
            prev->left = temp;
            
        }
        else{
            //insert in right
            prev->right = temp;
        }
        
        return ROOT;
    }
};