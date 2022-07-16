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
        if(root == nullptr){
            return 0;
        }
        queue<pair<TreeNode *, long long>> q;
        
        q.push({root, 0});
        
        long long width = 0;
        
        while(!q.empty()){
            int sz = q.size();
             long long subtract = q.front().second;  
            // To make the i start from 1 on every level
            
            //optimization done to avoid integer overflow
            
            
            long long LI; // left index
            long long RI; // right index
            
            for(int idx = 0 ; idx < sz ; idx++){
                auto front = q.front();
                q.pop();
                
                
                TreeNode * node = front.first;
                long long i = front.second - subtract ;
                
                if(idx == 0){
                    LI = i;
                }
                if(idx == sz-1){
                    RI = i;
                }
                
                if(node->left){
                    q.push({node->left, 2*i +1});
                }
                if(node->right){
                    q.push({node->right, 2*i +2});
                }
                
            }
            width = max(width, abs(RI-LI) +1);
        }
        
        return width;
    }
};