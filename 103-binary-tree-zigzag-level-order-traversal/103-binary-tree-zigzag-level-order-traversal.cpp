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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        bool zigzag = true;
        
        vector<vector<int>> ans;
        
        if(root == nullptr){
            return ans;
        }
        
        
        queue<TreeNode*>q;
        
        q.push(root);
        
        while(!q.empty()){
            
            auto sz = q.size();
            vector<int> level(sz,-1);
            for(int i = 0 ; i < sz ; i++){
                auto front = q.front();
                q.pop();
                
                // level.push_back(front->val);
                
                if(zigzag){
                    level[i] = front->val;
                    
                }
                else{   
                    level[sz - 1 - i] = front->val;
                    
                }
                
                if(front->left){
                    q.push(front->left);
                }

                if(front->right){
                    q.push(front->right);
                }
            }
            
            ans.push_back(level);
            
            zigzag = !zigzag;
        }
        
        return ans;
        
    }
};