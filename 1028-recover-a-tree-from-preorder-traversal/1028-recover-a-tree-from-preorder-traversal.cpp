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
        //hci research
    stack<TreeNode*> stk;
    int i = 0;
    while (i < traversal.size()) {
        int level = 0;
        while (traversal[i] == '-') {
            level++;
            i++;
        }
        int j = i;
        while (j < traversal.size() && traversal[j] != '-') {
            j++;
        }
        int val = stoi(traversal.substr(i, j - i));
        TreeNode* node = new TreeNode(val);
        if (level == stk.size()) {
            if (!stk.empty()) {
                stk.top()->left = node;
            }
        } else {
            while (level != stk.size()) {
                stk.pop();
            }
            stk.top()->right = node;
        }
        stk.push(node);
        i = j;
    }
    while (stk.size() > 1) {
        stk.pop();
    }
    return stk.top();
    }
};