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
    void inorder(TreeNode *root){
        if(root==nullptr){
            return ;
        }
        
        inorder(root->left);
        nums.push_back(root->val);
        inorder(root->right);
        
        return ;
    }
    bool twoSum(TreeNode *root, int k){
        int i = 0;
        int j = nums.size() -1;
        
        while ( i < j){
            int a = nums[i];
            int b = nums[j];
            int sum = a+b;
            if(sum ==k){
                return true;
            }
            else if(sum > k){
                j--;
            }
            else{
                i++;
            }
        }
        
        return false;
    }
    bool findTarget(TreeNode* root, int k) {
        inorder(root);  
        bool ans = twoSum(root, k);
        
        // TC ->O(N) + O(N) = O(2N) ==> O(N)
        // SC -> O(N)
        
        return ans;
        
        
    }
};