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

struct DS{
    int sum;
    bool isBST;
    int maxi;
    int mini;
};

class Solution {
public:
    DS helper(TreeNode *root, int &res){
       if(root != nullptr){
           DS LEFT = helper(root->left, res);
           DS RIGHT = helper(root->right, res);
           // cout << "root = " << root->val << ", leftmax = " << LEFT.maxi << " , rightmin = " << RIGHT.mini << endl;
           bool isbst = LEFT.isBST && RIGHT.isBST && root->val > LEFT.maxi && root->val < RIGHT.mini;
           
           int summ = LEFT.sum + root->val + RIGHT.sum ;
           
           if(isbst){
               res = max(res, summ);
           }
           
           return {summ, isbst, 
                   max({root->val, LEFT.maxi, RIGHT.maxi}), 
                   min({root->val, RIGHT.mini, LEFT.mini}) };
       }
        else{
            return {0, true, INT_MIN, INT_MAX};
        }

    }
    int maxSumBST(TreeNode* root) {
        int res = 0;
        helper(root, res);
        
        return res;
    }
};