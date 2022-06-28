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
    void solve(TreeNode *root, int level, vector<int> &ans){
        if(root== nullptr){
            return ;
        }
        
        if(level == ans.size()){
            ans.push_back(root->val);
        }
        
        solve(root->right , level+1 , ans);
        solve(root->left  , level+1 , ans);
        
        // for right view, we do --> root, right, left  (modified pre order traversal)
        
        // for left view, we do -> root, left, right (normal pre order traversal)
        
        return ;
        
        // TC - O(N);
        // SC - O(H) --> height of tree (Worst case -> skewed tree)
        
        
        
    }
    
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans;
        if(root== nullptr){
            return ans;
        }
        
        // TC - O(NLOGN)  -->Better soln below --> TC - O(N)
        // SC - O(N)
        
//         queue<pair<TreeNode*, int>> q; // node, row
//         map<int, int> mp ; // row, node->val
        
//         q.push({root,0});
        
//         while(!q.empty()){
//             auto front = q.front();
//             q.pop();
            
//             TreeNode* node = front.first;
//             int row = front.second;
            
//             mp[row] = node->val;  // in right/;eft view, we gotta do it with row
//             // instead of col
            
//             if(node->left){
//                 q.push({node->left, row+1});
//             }
//             if(node->right){
//                 q.push({node->right, row+1});
//             }
//         }
        
//         for(auto x : mp){
//             ans.push_back(x.second);
//         }
        
//         return ans;
        
        
        
        
        // modified pre order traversal (root, right, left)
        solve(root,0,  ans);
        return ans;
        
        
        
        
        
        
        
        
        
        
    }
};