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
    
    TreeNode *prev;
    void flatten(TreeNode* root) {
        
        
        if(root == nullptr){
            return ;
        }
        
        // With MORRIS TRAVERSAL
        // https://leetcode.com/problems/flatten-binary-tree-to-linked-list/discuss/1207642/JS-Python-Java-C%2B%2B-or-Simple-O(1)-Space-and-Recursive-Solutions-w-Explanation
        // TC - O(N)
        // SC - O(1)
        TreeNode* curr = root;
        while(curr != nullptr){
            if(curr->left){
                TreeNode* runner = curr->left;
                while(runner->right){
                    runner = runner->right;
                }
                runner->right = curr->right;
                curr->right = curr->left;
                curr->left = nullptr;
            }
            curr = curr->right;
        }
        
        return;
        
        
        
//         // Without MORRIS TRAVERSAL  (from striver video)
//         // TC -> O(N)
//         // SC -> O(N)
        
        
//         flatten(root->right);
//         flatten(root->left);
        
//         root->right = prev;
//         root->left = nullptr;
        
//         prev = root;
        // return;
        
        
        
        
    }
};