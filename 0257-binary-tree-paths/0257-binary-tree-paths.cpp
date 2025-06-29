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
    vector<string> ans;
    void f(TreeNode* root, string st){
        if(!root){
            return ;
        }

        st += to_string(root->val);

        if(root && !root->left && !root->right){
            // leaf node
            ans.push_back(st);
            return ;
        }

        f(root->left, st + "->");
        f(root->right, st + "->");

        return ;

    }
    vector<string> binaryTreePaths(TreeNode* root) {
        ans.clear();
        string s = "";
        f(root, s);
        return ans;
        
    }
};