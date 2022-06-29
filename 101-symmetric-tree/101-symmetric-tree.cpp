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
    bool isSame(TreeNode *p, TreeNode *q){
        // isSame() --> Leetcode 100
        // https://leetcode.com/problems/same-tree/
        
        if(p == nullptr && q== nullptr){
            return true;
        }
        if(p &&!q || !p && q){
            return false;
        }
        if(p->val != q->val){
            return false;
        }
        
        //checking alternate nodes
        return isSame(p->right, q->left) && isSame(p->left, q->right);
    }
    
    bool isSymmetric(TreeNode* root) {
        
        // Recursive soln
        
        if(root == nullptr){
            return true;
        }
        
//         return isSame(root->left, root->right);
        
        
        // Iterative / non recursive soln
        
        queue<TreeNode*> q;
        q.push(root->left);
        q.push(root->right);
        
        while(!q.empty()){
            
            auto l = q.front();
            q.pop();
            auto r = q.front();
            q.pop();
            
            if(l == nullptr && r == nullptr){
                continue; // critical
                // see test case --> [9,-42,-42,null,76,76,null,null,13,null,13]
            }
            if(l == nullptr && r != nullptr || l != nullptr && r == nullptr ){
                return false;
            }
            
            if(l->val != r->val){
                return false;
            }
            
            
            q.push(l->left);
            q.push(r->right);
            
            q.push(l->right);
            q.push(r->left);
            
        }
        
        return true;
    
    }
};