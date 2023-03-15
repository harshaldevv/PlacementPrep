class Solution {
public:
    int deepestLeavesSum(TreeNode* root) {
        //hci research
        int maxDepth = 0;
        int sum = 0;
        dfs(root, 0, maxDepth, sum);
        return sum;
    }
    
    void dfs(TreeNode* node, int depth, int& maxDepth, int& sum) {
        if (!node) {
            return;
        }
        if (!node->left && !node->right) { // leaf node
            if (depth > maxDepth) {
                maxDepth = depth;
                sum = node->val;
            } else if (depth == maxDepth) {
                sum += node->val;
            }
            return;
        }
        dfs(node->left, depth + 1, maxDepth, sum);
        dfs(node->right, depth + 1, maxDepth, sum);
    }
};
