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
        
        while(root){
            TreeNode *left = root->left;
            TreeNode *right = root->right;
            

            if(left){
                
                TreeNode* runner = left;
                
                while(runner && runner->right){
                    runner = runner->right;
                }

                runner->right = right; 

                root->left = nullptr;
                root->right = left;
                
            }
            
            root = root->right;
            cout << endl;

        }
        
        return ;
        
    }
};