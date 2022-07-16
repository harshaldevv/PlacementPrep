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
    TreeNode* createtree(vector<int>& preorder, int prestart, int preend, vector<int>& inorder, int instart, int inend, unordered_map<int, int> &mp){
        
        
        if(preend < prestart || inend < instart){
            return nullptr;
        }
        
        int rootVal = preorder[prestart];
        int indx = mp[rootVal];  // get index from the inorder array (use the map we created);
        
        TreeNode *root = new TreeNode(rootVal);
        
        
        int numberstoTheLeft = indx - instart;
        
        root->left = createtree(preorder, prestart +1 ,prestart + numberstoTheLeft, inorder, instart, indx -1, mp);
        root->right = createtree(preorder, prestart +1 + numberstoTheLeft,  preend, inorder, indx +1, inend, mp);
        
        
        return root;
            
        
        
        
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        // make map of inorder
        
        unordered_map<int, int> mp; // value, index
        
        int n = inorder.size();
        
        for(int i = 0 ;  i < n ; i++){
            int x = inorder[i];
            mp[x] = i;
        }
        
        return createtree(preorder, 0 , preorder.size()-1, inorder, 0, inorder.size() -1 , mp);
        
    }
};