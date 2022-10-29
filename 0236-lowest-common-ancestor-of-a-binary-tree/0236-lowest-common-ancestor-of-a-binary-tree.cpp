/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode *LCA(TreeNode* p, TreeNode* q, TreeNode* root){
        
        if(!root){
            return root;
        }    
        
        if(root == p){
            // cout << "allo" << endl;
            // cout << "p = " << root->val << endl;
            return p;
        }
        
        if(root == q){
            // cout << "hereee" << endl;
            // cout << "q = " << root->val << endl;
            return q;
        }
        
        
        TreeNode* left = LCA(p,q, root->left);
        TreeNode* right = LCA(p,q, root->right);
        
    
        if(left && right){
            // cout << "hi"<<endl;
            return root;
        }
        else if(!left && right){
            return right;
        }
        else{
            return left;
        }
        
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        
        if(!root){
            return root;
        }
        
        return LCA(p,q, root);
        
    }
};