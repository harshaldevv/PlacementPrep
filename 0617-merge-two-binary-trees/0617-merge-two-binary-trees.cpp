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
        if(!p && !q){
            return nullptr;
        }
        
        if(p && !q){
            return p;
        }
        
        if(!p && q){
            return q;
        }
        
        
        // dono are non null
        // sum up
        
        p->val += q->val;
        
        TreeNode *leftTree = merge(p->left, q->left);
        
        TreeNode *rightTree = merge(p->right, q->right);
        
        p->left = leftTree;
        p->right = rightTree;
        
        return p;
    }
    
    TreeNode* mergeTrees(TreeNode* p, TreeNode* q) {
        if(!p && !q){
            return nullptr;
        }
        
        if(p &&!q){
            return p;
        }
        
        if(!p && q){
            return q;
        }
        
        return merge(p,q);
        
        // return p;
        
        
        
    }
};