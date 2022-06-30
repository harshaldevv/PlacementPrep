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
    int count = 0;
    int ans;
    
    void inorder(TreeNode *root, int k){
        if(root == nullptr){
            return ;
        }
        
        inorder(root->left, k);
        
        //root
        count++;
        if(count == k){
            ans = root->val;
            return;
        }
        
        inorder(root->right, k);
        
        return ;
    }
    
    int kthSmallest(TreeNode* root, int k) {
        // for kth  smallest, we do NORMAL INORDER
        // for kth largest, we do REVERSE INORDER (right, root, left)
        
        // TC - O(N)
        // SC - O(N) --> recursive stack space  --> can be optimised by using morris traversal to O(1)
        
        
        inorder(root, k);
        return ans;
    }
};