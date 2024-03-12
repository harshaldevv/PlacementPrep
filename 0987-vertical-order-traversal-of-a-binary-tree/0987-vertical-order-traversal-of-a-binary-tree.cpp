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
        
        map<int, map<int, multiset<int>>> mp;
        
        
        queue<pair<TreeNode*, pair<int, int>>> q;
        q.push({root, {0, 0}});
        
        while(!q.empty()){
            int sz = q.size();
            while(sz--){
                auto front = q.front();
                q.pop();
                auto nodee = front.first;
                auto col = front.second.first;
                auto row = front.second.second;
                
                mp[col][row].insert(nodee->val);
                
                if(nodee->left){
                    q.push({nodee->left, {col-1, row+1}});
                }
                
                if(nodee->right){
                    q.push({nodee->right, {col+1, row+1}});
                }
            }
        }
        
        for(auto&it : mp){
            vector<int> temp;
            for(auto &x : it.second){
                for(auto &p : x.second){
                    temp.push_back(p);
                }
            }
            ans.push_back(temp);
        }
        
        return ans;
        
        
    }
};