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
    vector<int> ans;
    vector<int> preorderTraversal(TreeNode* root) {
        
        //iterative soln -- > TC - O(N), SC - O(N)
        
        if(root == nullptr){
            return ans;
        }
        
        stack<TreeNode*> st; // push  right , then left, cuz stack works in LIFO
        
        st.push(root);
        
        while(!st.empty()){
            auto front = st.top();
            st.pop();
            cout << front->val << " ";
            ans.push_back(front->val);
            
            // push  right , then left, cuz stack works in LIFO
            if(front->right){
                st.push(front->right);
            }
            
            if(front->left){
                st.push(front->left);
            }
        }
        
        return ans;
        
        
        
        
        // Recursive SOln - > TC - O(N), SC - O(N)
        
        // if(root == NULL){
        //     return ans;
        // }
        // ans.push_back(root->val); // print(root->data);
        // preorderTraversal(root->left);
        // preorderTraversal(root->right);
        // return ans;
        
    }
};