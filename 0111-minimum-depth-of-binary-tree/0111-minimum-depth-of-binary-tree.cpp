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
    
    
    int minDepth(TreeNode* root) {
        
        if(root == nullptr){
            return 0;
        }
        
        if(!root->left && !root->right){
            return 1;
        }        
        
        queue<TreeNode*> q;
        
        q.push(root);
        
        int l = 0 ;
        
        while(!q.empty()){
            int sz = q.size();
            while(sz--){
                auto front = q.front();
                q.pop();
                
                if(!front->left && !front->right){
                    return l+1;
                }
                
                if(front->left){
                    q.push(front->left);
                }
                
                if(front->right){
                    q.push(front->right);
                }
            }
            l++;
        }
        
        return 5;
        
        
        
        
    }
};