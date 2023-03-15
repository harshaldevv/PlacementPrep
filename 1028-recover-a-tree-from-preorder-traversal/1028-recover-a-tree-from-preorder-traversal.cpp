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
    TreeNode* recoverFromPreorder(string traversal) {
        
        // hci research
        
        
        stack<TreeNode*> stk; // Use a stack to store the current node at each depth
        int i = 0; // index of traversal string
        while (i < traversal.size()) {
            int depth = 0;
            while (traversal[i] == '-') { // Calculate the depth of the current node
                ++depth;
                ++i;
            }
            int num = 0;
            while (i < traversal.size() && traversal[i] != '-') { // Read the value of the current node
                num = num * 10 + (traversal[i] - '0');
                ++i;
            }
            TreeNode* cur = new TreeNode(num);
            if (depth == stk.size()) { // The current node is the left child of the top node in the stack
                if (!stk.empty()) stk.top()->left = cur;
            } else { // The current node is a right child, need to pop nodes from the stack until we find the parent
                while (depth < stk.size()) stk.pop();
                stk.top()->right = cur;
            }
            stk.push(cur); // Push the current node into the stack
        }
        while (stk.size() > 1) stk.pop(); // The root is the only node left in the stack
        return stk.top();
    }
};