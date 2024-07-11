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
        
        TreeNode* ptr = root;
        if(!root){
            return ;
        }

        while(ptr){
            if(ptr && ptr->left){
                TreeNode* runner = ptr->left;

                while(runner){
                    if(runner->right){
                        runner = runner->right;
                    }
                    else if(runner->left){
                        runner = runner->left;
                    }
                    else{
                        break;
                    }
                }
                

                runner->right = ptr->right;
                ptr->right = ptr->left;
                ptr->left = nullptr;

            }
            
            ptr = ptr->right;
        }
        
        
    }
};