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
//     int helper(TreeNode* root){
//         if(!root){
//             return 0;
//         }
        
//         return 1 + max(helper(root->left), helper(root->right));
//     }
    
    int maxDepth(TreeNode* root) {
        
        // DFS
//         if(!root){
//             return 0;
//         }
        
//         return helper(root);
        
        // BFS
        if(!root){
            return 0;
        }
        
        int ans = 0;
        
        queue<pair<TreeNode*, int>> q;
        q.push({root, 1});
        
        while(!q.empty()){
            int sz = q.size();
            while(sz--){
                auto front = q.front();
                q.pop();
                auto nodee = front.first;
                int h = front.second;
                
                ans = max(h, ans);
                
                if(nodee->left){
                    q.push({nodee->left, h+1});
                }
                
                if(nodee->right){
                    q.push({nodee->right, h+1});
                }
            }
        }
        
        return ans;
        
        
    }
};