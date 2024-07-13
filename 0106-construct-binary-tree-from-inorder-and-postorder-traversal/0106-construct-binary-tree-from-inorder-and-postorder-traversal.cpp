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
    
    TreeNode* f(int poststart, int  postend, vector<int> &postorder, int instart, int inend, vector<int> &inorder, unordered_map<int, int> &inorder_map){
        
        if(poststart > postend || instart > inend){
            return nullptr;
        }
        
        
        int rootval = postorder[postend];
        int inorder_index = inorder_map[rootval];
        int leftside = inorder_index - instart;
        
        TreeNode* root = new TreeNode(rootval);
        
        root->left =  f(poststart, poststart + leftside -1 , postorder, instart, inorder_index-1, inorder, inorder_map);
        root->right = f(poststart + leftside, postend -1, postorder, inorder_index+1, inend, inorder, inorder_map);
        
        return root;
        
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        
        unordered_map<int, int> inorder_map;
        for(int i = 0; i < inorder.size() ; i++){
            inorder_map[inorder[i]] = i;
        }
        
        return f(0, postorder.size() -1, postorder, 0, inorder.size() -1, inorder, inorder_map);
        
    }
};