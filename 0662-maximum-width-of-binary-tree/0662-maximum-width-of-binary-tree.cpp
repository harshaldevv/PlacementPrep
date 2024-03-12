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
    int widthOfBinaryTree(TreeNode* root) {
        int width = 0;
        if(!root){
            return width;
        }
        queue<pair<TreeNode*, long long>> q;
        q.push({root, 0});
        
        while(!q.empty()){
            int sz = q.size();
            int left = q.front().second;
            int right = q.back().second;
            
            width = max(width, right - left +1); // max width at a level
            
            while(sz--){
                auto front= q.front();
                q.pop();
                auto nodee= front.first;
                int col = front.second;
                
                if(nodee->left){
                    q.push({nodee->left, 2LL*col +1});
                }
                
                if(nodee->right){
                    q.push({nodee->right, 2LL*col+2});
                }
            }
        }
        
        
        return width;
        
    }
};