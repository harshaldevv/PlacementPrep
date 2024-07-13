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
    TreeNode* f(int prestart, int  preend, vector<int> &preorder, int instart, int inend, vector<int> &inorder, unordered_map<int, int> &inorder_map){
        
        if(prestart > preend || instart > inend){
            return nullptr;
        }
        
        
        int rootval = preorder[prestart];
        int inorder_index = inorder_map[rootval];
        int leftside = inorder_index - instart;
        
        TreeNode* root = new TreeNode(rootval);
        
        root->left =  f(prestart +1, prestart + leftside , preorder, instart, inorder_index-1, inorder, inorder_map);
        root->right = f(prestart + leftside + 1, preend, preorder, inorder_index+1, inend, inorder, inorder_map);
        
        return root;
        
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        
        unordered_map<int, int> inorder_map;
        for(int i = 0; i < inorder.size() ; i++){
            inorder_map[inorder[i]] = i;
        }
        
        return f(0, preorder.size() -1, preorder, 0, inorder.size() -1, inorder, inorder_map);
        
    }
};