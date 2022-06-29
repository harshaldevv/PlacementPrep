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
        // instead of using recursion here, we could also use queue here 
        // as shown in striver's video, but i find this recursion intutive 
        // and it came naturally to me
        
        
        if(root == nullptr){
            return ;
        }
        if(visited.find(root) != visited.end()){
            // this is done to prevent visiting the same node jahan se hum aye the
            // remove this line to see what happens for example 1, you'll understand
            
            // node already visited --> therefore no use of this node, we can return
            return ;
        }
        
        visited.insert(root);
        
        if(dist == k){
            ans.push_back(root->val);
            return;
        }
        
        // go LEFT  (down)
        doTraversal(root->left, dist+1, k , ans);
        
        // go RIGHT (down)
        doTraversal(root->right, dist+1, k , ans);
        
        // go UP
        // access parent of root from the parent data structure aka MAP which we created
        doTraversal(mp[root], dist+1, k, ans);
        
        return ;
        
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
       
        
        // In this question, we had to even move upwards from a our target node
        // downwards me left or right toh easily jaa sakte the, lekin
        // upar jane ka koi tarika tha nahi 
        
        // therefore to tackle this problem, we store every node's parent in a 
        // data structure (here map), to quickly gets its parent 
        
        // We do BFS to traverse each level and create our "parents" wala Data struc (see code)
        
        
        getParent(root);
        
        // start traversal from target;
        vector<int> ans;
        doTraversal(target, 0, k, ans);
        
        return ans;
        
        
    }
};