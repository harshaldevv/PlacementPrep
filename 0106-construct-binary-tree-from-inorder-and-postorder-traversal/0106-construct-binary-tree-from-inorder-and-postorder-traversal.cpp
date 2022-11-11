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
    // pre order -> root, left, right
    // inorder -> left, root, right
    
    
    // post order -> left, right, root
    // inorder -> left, root, right
    
    TreeNode* createTree(vector<int> &in, int instart, int inend, vector<int> &post, int poststart, int postend, unordered_map<int, int> &mp ){
        if(instart > inend || poststart > postend){
            return NULL;
        }
        
        int rootval = post[postend];
        int indx = mp[rootval];
        
        TreeNode* root = new TreeNode(rootval);
        
        int blah =  indx - instart ; // left
        
        
        root->left = createTree(in, instart, indx -1, post,  poststart, poststart + blah -1, mp);
        root->right = createTree(in, indx+1, inend, post,  poststart + blah, postend-1, mp);
                
        
        
        return root;
        
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        
        int n = inorder.size();
        
        unordered_map<int, int> mp;
        for(int i = 0 ; i < n ; i++){
            int x = inorder[i];
            mp[x] = i;
        }
        
        return createTree(inorder, 0, n-1, postorder, 0, n-1, mp);
        
    
    }
};