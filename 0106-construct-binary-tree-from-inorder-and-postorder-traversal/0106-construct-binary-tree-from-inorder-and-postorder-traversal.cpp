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
    TreeNode *makeTree(int l, int r, vector<int> &inorder, int l1, int r1, vector<int> &postorder, unordered_map<int, int> &mp){
        if(l>r || l1 > r1){
            return NULL;
        }
        
        int rootval = postorder[r1];
        TreeNode *root = new TreeNode(rootval);
        
        int indx = mp[rootval];
        int leftLength = indx - l;
        
        root->left = makeTree(l, indx -1, inorder, l1, l1 + leftLength -1, postorder, mp);
        root->right = makeTree(indx+1, r, inorder, l1+leftLength , r1-1, postorder, mp);
    
        return root;
        
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int n = inorder.size();
        unordered_map<int, int > mp;
        
        for(int i = 0; i < n ; i++){
            mp[inorder[i]] = i; 
        }
        
        return makeTree(0, n-1, inorder, 0, n-1, postorder, mp);
        
    }
};