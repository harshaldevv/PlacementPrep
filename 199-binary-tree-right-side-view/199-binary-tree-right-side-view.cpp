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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans;
        if(root== nullptr){
            return ans;
        }
        
        queue<pair<TreeNode*, int>> q; // node, row
        map<int, int> mp ; // row, node->val
        
        q.push({root,0});
        
        while(!q.empty()){
            auto front = q.front();
            q.pop();
            
            TreeNode* node = front.first;
            int row = front.second;
            
            mp[row] = node->val;
            
            if(node->left){
                q.push({node->left, row+1});
            }
            if(node->right){
                q.push({node->right, row+1});
            }
        }
        
        for(auto x : mp){
            ans.push_back(x.second);
        }
        
        return ans;
            
    }
};