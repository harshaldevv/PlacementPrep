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
    void helper(TreeNode* root, map<int, map<int, multiset<int>>> &mp, int col, int row){
        if(!root){
            return ;
        }
        
        mp[col][row].insert(root->val);
        
        helper(root->left, mp, col-1, row+1);
        helper(root->right, mp, col+1, row+1);
        
        return ;
    }
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        
        // via dfs
        vector<vector<int>> ans;
        if(!root){
            return ans;
        }
        
        map<int, map<int, multiset<int>>> mp;
        
        helper(root, mp, 0,0); // col, row
        
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