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
    
    
    TreeNode* constructTree(vector<int>&preorder,int prestart, int preend,vector<int>&inorder, int instart, int inend, unordered_map<int, int> &mp){
        
        if(prestart > preend || instart > inend){
            return nullptr;
        }
        
        TreeNode *root = new TreeNode(preorder[prestart]);
        
        int i = mp[root->val]; //index of root->val in inorder
        // i ke left me poora root->left ka maal
        // i ke right me poora root->right ka maal
        int numsleft = i - instart;
        
        
        root->left = constructTree(preorder, prestart +1, prestart+ numsleft, inorder, instart, i -1, mp);
        root->right = constructTree(preorder, prestart + numsleft +1, preend, inorder, i+1, inend, mp);
        
        return root;
        
    }
   
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        
        unordered_map<int, int> mp;
        
        for(int i = 0 ; i < inorder.size() ; i++){
            auto x = inorder[i];
            mp[x] = i;
        }
        
       
        TreeNode *root = constructTree(preorder, 0, preorder.size() -1, inorder, 0, inorder.size()-1, mp);
        
       
        return root;
        
         
        
    }
};