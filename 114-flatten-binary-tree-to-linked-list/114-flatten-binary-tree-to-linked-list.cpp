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
    void flatten(TreeNode* root) {
        
        TreeNode *ptr = root;
        
        while(ptr){
            if(ptr->left){
                TreeNode *p = ptr->left;
                TreeNode *q = ptr->right;
                // now go right right
                while(p->right != nullptr){
                    p = p->right;
                }
                
                p->right = q;
                
                ptr->right = ptr->left;
                ptr->left = NULL;
                
            }
            
            ptr = ptr->right;
        }
        
        return ;
        
    }
};