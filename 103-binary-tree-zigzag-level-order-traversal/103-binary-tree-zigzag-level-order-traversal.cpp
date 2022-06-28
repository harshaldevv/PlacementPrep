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
        
//         while(!q.empty()){
            
//             int sz = q.size();
//             vector<int>level(sz, -1);
            
//             for(int i = 0 ; i < sz ; i++){
                
//                 auto front = q.front();
//                 q.pop();
                
//                 if(!toRev){
//                     level[i] = front->val;
//                 }
//                 else{
//                     level[sz - 1 - i] = front->val;
//                 }
                
//                 if(front->left){
//                     q.push(front->left);
//                 }
                
//                 if(front->right){
//                     q.push(front->right);
//                 }
//             }
            
//             toRev = !toRev;
//             ans.push_back(level);
            
//         } --> OP
        
        
        //now actually doing zig zag traversal
        
        deque<TreeNode*> dq;
        dq.push_back(root);
        bool left2Right = true;
        
        while(!dq.empty()){
            int sz = dq.size();
            
            vector<int> level;
            
            for(int i = 0 ; i< sz ; i++){
                
                if(!left2Right){
                    auto front = dq.back();
                    dq.pop_back();
                    
                    level.push_back(front->val);
                    
                    if(front->right){
                        dq.push_front(front->right);
                    }
                    
                    if(front->left){
                        dq.push_front(front->left);
                    }
                    
                }
                else{
                    auto front = dq.front();
                    dq.pop_front();
                    
                    level.push_back(front->val);
                    
                    if(front->left){
                        dq.push_back(front->left);
                    }
                    
                    if(front->right){
                        dq.push_back(front->right);
                    }
                    
                }
                
            }
            
            
            ans.push_back(level);
            left2Right = !left2Right ;
            
        }
        
        return ans;
    }
};