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
    int f(TreeNode* root, long long int mini, long long int maxi){

        if(!root){
            return true;
        }

        if(root->val <= mini || root->val >= maxi){
            return false;
        }

        bool lefty =  f(root->left, mini, root->val);
        bool righty = f(root->right, root->val, maxi);

        return lefty && righty;
    }
    bool isValidBST(TreeNode* root) {
        return f(root, LLONG_MIN, LLONG_MAX);
    }
};