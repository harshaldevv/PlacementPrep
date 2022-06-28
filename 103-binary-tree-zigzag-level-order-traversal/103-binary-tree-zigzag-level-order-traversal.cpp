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
        // do level order traversal
        // and then reverse every 2nd sublist in it
        
        
        vector<vector<int>> ans;
        
        if(root == nullptr){
            return ans;
        }
        
        queue<TreeNode*> q;
        q.push(root);
        bool toRev = false;
        
//         while(!q.empty()){
//             int sz = q.size();
            
//             vector<int> level;
            
//             while(sz--){
//                 auto front = q.front();
//                 q.pop();
                
//                 level.push_back(front->val);
                
//                 if(front->left){
//                     q.push(front->left);
//                 }
                
//                 if(front->right){
//                     q.push(front->right);
//                 }
//             }
            
//             if(toRev){
//                 reverse(level.begin(), level.end());
//                 toRev = false;
//             }
//             else{
//                 //push level as it is 
//                 toRev = true;
//             }
            
//             ans.push_back(level);
//         }
        
        // ^^ this approach used reverse() 
        
        // below approach without using reverse()
        
        while(!q.empty()){
            int sz = q.size();
            vector<int>level(sz, -1);
            
            for(int i = 0 ; i < sz ; i++){
                
                auto front = q.front();
                q.pop();
                
                if(!toRev){
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
            
            toRev = !toRev;
            ans.push_back(level);
        }
        
        return ans;
    }
};