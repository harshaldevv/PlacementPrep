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
        
        if(!root){
            return ;
        }
        
        TreeNode *p = root;
        
        while(p){
            cout << "p = " << p->val << endl;
            auto R = p->right;
            auto L = p->left;
            
            if(L != NULL){
                auto runner = L;
                
                while(runner && runner->right){
                    runner = runner->right;
                }
        
                runner->right = p->right;
                p->right = p->left;
                p->left = NULL;
                
                
            }
            
            p =  p->right;
        }
        
        
        return ;
        
    }
};