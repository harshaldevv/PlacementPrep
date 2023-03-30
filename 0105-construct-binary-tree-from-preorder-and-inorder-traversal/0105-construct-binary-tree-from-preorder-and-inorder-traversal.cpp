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
        //hci research
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        // Create a hash map to store the indices of the nodes in the inorder traversal
        unordered_map<int, int> inorder_map;
        for (int i = 0; i < inorder.size(); i++) {
            inorder_map[inorder[i]] = i;
        }
        // Build the tree recursively
        return buildTreeRecursive(preorder, inorder, inorder_map, 0, preorder.size() - 1, 0, inorder.size() - 1);

    }
    
    TreeNode* buildTreeRecursive(vector<int>& preorder, vector<int>& inorder, unordered_map<int, int>& inorder_map, int preorder_start, int preorder_end, int inorder_start, int inorder_end) {
        // Base case: empty range
        if (preorder_start > preorder_end) {
            return nullptr;
        }
        // Create the root node
        TreeNode* root = new TreeNode(preorder[preorder_start]);
        // Find the index of the root node in the inorder traversal
        int inorder_root = inorder_map[root->val];
        // Compute the size of the left subtree
        int left_subtree_size = inorder_root - inorder_start;
        // Recursively build the left subtree
        root->left = buildTreeRecursive(preorder, inorder, inorder_map, preorder_start + 1, preorder_start + left_subtree_size, inorder_start, inorder_root - 1);
        // Recursively build the right subtree
        root->right = buildTreeRecursive(preorder, inorder, inorder_map, preorder_start + left_subtree_size + 1, preorder_end, inorder_root + 1, inorder_end);
        // Return the root node
        return root;
    }
};
