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
    unordered_set<TreeNode*> visited;
    
    void getParent(TreeNode *root){
        // via BFS (level order) traversal
        
        if(root == nullptr){
            return ;
        }
        
        queue<TreeNode*> q;
        q.push(root);
        
        while(!q.empty()){
            int sz = q.size();
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
    
    void doTraversal(TreeNode *root, int dist, int k, vector<int> &ans){
        if(root == nullptr){
            return ;
        }
        if(visited.find(root) != visited.end()){
            // node already visited
            return ;
        }
        
        visited.insert(root);
        
        if(dist == k){
            ans.push_back(root->val);
            return;
        }
        
        //go LEFT 
        doTraversal(root->left, dist+1, k , ans);
        
        // go RIGHT
        doTraversal(root->right, dist+1, k , ans);
        
        // go UP
        doTraversal(mp[root], dist+1, k, ans);
        
        return ;
        
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
       
        
        
        
        getParent(root);
        
        // start traversal from root;
        vector<int> ans;
        doTraversal(target, 0, k, ans);
        
        return ans;
        
        
    }
};