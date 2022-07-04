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
    int sum;
    int solve(TreeNode *root){
        if(root== nullptr){
            return 0;
        }
        
        //left
        int leftSum = max(solve(root->left), 0);
        
        // right
        int rightSum = max(solve(root->right), 0);
        
        sum = max(sum, root->val + leftSum + rightSum); // sum involving root + left + sum
        
        return root->val + max(leftSum, rightSum); 
        // passing sum to the above level --> therefore root-> val isnt added to return
        
        
        /***
        HELPFUL POST
        
        1)
        https://leetcode.com/problems/binary-tree-maximum-path-sum/discuss/603423/Python-Recursion-stack-thinking-process-diagram
        
        2)
        https://leetcode.com/problems/binary-tree-maximum-path-sum/discuss/603072/C%2B%2B-solution-O(n)-with-detailed-explanation
        
        ***/
        
    }
    int maxPathSum(TreeNode* root) {
        // Trivial soln -- >TC -  O(N^2) approach 
        
        // This approach --> TC - O(N) approach
        sum = INT_MIN;
        
        solve(root);
        
        return sum;
        
    }
};