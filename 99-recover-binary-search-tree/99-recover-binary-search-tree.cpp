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
    vector<int> nums;
    vector<TreeNode*> NODES;
    
    TreeNode* firstElement = nullptr;
    TreeNode* secondElement = nullptr;
    // The reason for this initialization is to avoid null pointer exception in the first comparison when 
    // prevElement has not been initialized
    TreeNode* prevElement = new TreeNode(INT_MIN);
    
    void inorder(TreeNode * root){
        if(root==nullptr){
            return ;
        }
        
        inorder(root->left);
        
        // do some work here
        // nums.push_back(root->val);
        // NODES.push_back(root);
        
        if(firstElement == nullptr && prevElement->val > root->val){
            firstElement = prevElement;
        }
        
        if(firstElement != nullptr && prevElement->val > root->val){
            secondElement = root;
        }
        prevElement = root;
        
        
        inorder(root->right);
        
        return ;
    }
    void recoverTree(TreeNode* root) {
        inorder(root);
        
        swap(firstElement->val, secondElement->val);
        
        return ;
      
    }
};