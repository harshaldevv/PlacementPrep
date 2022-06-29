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
    int countNodes(TreeNode* root) {
        int nodes = 0;
        if(root == nullptr){
            return nodes;
        }
        
        queue<TreeNode*> q;
        q.push(root);
        
        while(!q.empty()){
            int sz = q.size();
            while(sz--){
                auto front = q.front();
                q.pop();
                nodes++;
                
                if(front->left){
                    q.push(front->left);
                }
                
                if(front->right){
                    q.push(front->right);
                }
            }
        }
        
        return nodes;
        
    }
};