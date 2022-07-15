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
        
        
        queue< pair< TreeNode*, pair<int, int> >> q;
        
        q.push({root, {0,0}});
        
        
        //col, 
        map<int, map<int, multiset<int>> > mp;
        
        while(!q.empty()){
            int sz = q.size();
            for(int i = 0 ; i < sz ; i++){
                auto front = q.front();
                q.pop();
                
                TreeNode* node = front.first;
                int col  = front.second.first;
                int row = front.second.second;
                
                mp[col][row].insert(node->val);
                
                if(node->left){
                    q.push({node->left, {col-1, row+1}});
                }
                if(node->right){
                    q.push({node->right, {col+1, row+1}});
                } 
            }
        }
        
        for(auto &x : mp){
            vector<int> temp;
            for(auto &it : x.second){
                for(auto &p : it.second){
                    temp.push_back(p);
                }
            }
            ans.push_back(temp);
        }
        
        return ans;
    }
};