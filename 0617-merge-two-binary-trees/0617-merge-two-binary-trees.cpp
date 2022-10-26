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
    
    TreeNode* merge(TreeNode *p, TreeNode *q){
        
        if(!p && q){
            return q;
        }
        
        if(p && !q){
            return p;
        }
        
        
        if(!p && !q){
            
            return nullptr;
            
        }
        
        p->val += q->val;
        
        p->left = merge(p->left, q->left);
        p->right = merge(p->right, q->right);
        
        return p;
        
    }
    TreeNode* mergeTrees(TreeNode* p, TreeNode* q) {
        
        
        
        return merge(p,q);
        
        // return p;
        
    }
};