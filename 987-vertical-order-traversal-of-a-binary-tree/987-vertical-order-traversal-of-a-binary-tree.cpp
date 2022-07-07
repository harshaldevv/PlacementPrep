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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        
        
        vector<vector<int>> ans;
        
        if(root == nullptr){
            return ans;
        }
        
        
        queue<pair<TreeNode*, pair<int, int>>> q; // node, vertical, level
        
        map<int, map<int, multiset<int>>> mp; // --> vertical, level, nodes->val
        
        q.push({root,{0,0}});
        
        while(!q.empty()){
            int sz = q.size();
            
            while(sz--){
                auto front = q.front();
                q.pop();
                
                TreeNode * node = front.first;
                int v = front.second.first;
                int level = front.second.second;
                mp[v][level].insert(node->val);
                
                if(node->left){
                    q.push({node->left, {v-1, level +1}});
                }
                if(node->right){
                    q.push({node->right,{v+1, level+1}});
                }
            }
            
        }
        
        // for(auto it : mp){
        //     vector<int> col;
        //     for(auto p : it.second){
        //         col.insert(col.end(), p.second.begin(), p.second.end());
        //     }
        //     ans.push_back(col);
        // }
        
        for(auto it :mp){
            vector<int> col;
            for(auto p : it.second){
                for (auto x: p.second) {
                    col.push_back(x);
                }
            }
            ans.push_back(col);
        }
        
        return ans;
        
        
    }
};