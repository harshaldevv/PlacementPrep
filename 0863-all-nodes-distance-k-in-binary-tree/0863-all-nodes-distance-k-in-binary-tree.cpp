/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:

    unordered_map<TreeNode*, TreeNode*> mp;
    
    void makeParent(TreeNode* root){
        
        mp[root] = nullptr;
        
        queue<TreeNode*> q;
        
        q.push(root);
        
        while(!q.empty()){
            auto sz = q.size();
            
            while(sz--){
                
                auto front = q.front();
                q.pop();
                
                if(front->left){
                    q.push(front->left);
                    mp[front->left] = front;
                }
                
                if(front->right){
                    q.push(front->right);
                    mp[front->right] = front;
                }
            }
        }
        
        return ;
        
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        
        mp.clear();
        
        vector<int> ans;
        
        if(!root){
            return ans;
        }
        
        
        
        makeParent(root);
    
        unordered_set<TreeNode*> vis;
        
        queue<TreeNode*> q;
        
        q.push(target);
        vis.insert(target);
        
        
        int c = 0;
        bool done = false;
        while(!q.empty()){
            auto sz = q.size();
            
            while(sz--){
                auto front = q.front();
                q.pop();
                
                if(c == k){
                    
                    ans.push_back(front->val);
                    done = true;
                }
                
                if(front->left && vis.find(front->left) == vis.end()){
                    q.push(front->left);
                    vis.insert(front->left);
                }
                
                if(front->right && vis.find(front->right) == vis.end()){
                    q.push(front->right);
                    vis.insert(front->right);
                }
                
                if(mp[front] && vis.find(mp[front]) == vis.end()){
                    q.push(mp[front]);
                    vis.insert(mp[front]);
                }
            }
            
            c++;
            
            if(done){
                break;
            }
        }
        
        return ans;
        
    }
};