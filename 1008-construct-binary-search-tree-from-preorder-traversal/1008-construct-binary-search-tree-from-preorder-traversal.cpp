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
    
    TreeNode *makeTree(vector<int> &pre,int prestart,int preend,vector<int> &in,int instart,int inend,unordered_map<int,int> &mp){
        
        
        if(prestart > preend || instart > inend){
            return nullptr;
        }
        
        int rootval = pre[prestart];
        
        TreeNode *root = new TreeNode(rootval);
        
        int root_index = mp[root->val];
        
        int numsleft = root_index - instart;
        
        root->left = makeTree(pre, prestart +1, prestart + numsleft, in, instart, root_index -1, mp);
        root->right = makeTree(pre, prestart + numsleft + 1, preend, in, root_index +1, inend, mp);
        
        return root;
        
        
    }
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        
        // same as construct Btree from preorder and inorder
        // here given we've to create BST, therefore inorder of BST = sorted array 
        
        int n = preorder.size();
        
        vector<int> inorder = preorder;
        sort(inorder.begin(), inorder.end());
        
        unordered_map<int, int> mp;
        for(int i = 0 ; i < n ;i++){
            int x = inorder[i];
            mp[x] = i;
        }
        
        return makeTree(preorder, 0, preorder.size() -1, inorder, 0, inorder.size() -1, mp);
        
    }
};