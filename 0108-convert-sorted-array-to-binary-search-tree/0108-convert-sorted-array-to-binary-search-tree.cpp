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
    TreeNode* construct(int l, int r, vector<int> &nums){
        if(l>r){
            return NULL;
        }
        
        int indx = l + (r-l)/2;
        int rootval = nums[indx];
        
        TreeNode *temp = new TreeNode(rootval);
        
        temp->left = construct(l, indx-1, nums);
        temp->right = construct(indx+1, r, nums);
        
        return temp;
    }
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        int l = 0;
        int r = nums.size() -1;
        
        return construct(l,r, nums);
        
    }
};