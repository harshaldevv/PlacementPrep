/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
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
    TreeNode *constructTree(vector<int> &nodes, int l , int r){
        if(r < l){
            return nullptr;
        }
        
        
        int mid = l + (r-l)/2;
        
        int rootval = nodes[mid];
        
        TreeNode *root = new TreeNode(rootval);
        
        root->left = constructTree(nodes, l, mid -1);
        root->right = constructTree(nodes, mid +1, r);
        
        return root;
        
    }
    
    TreeNode* sortedListToBST(ListNode* head) {
        if(head == nullptr){
            return nullptr;
        }
        vector<int> nodes;
        
        ListNode *ptr  = head;
        
        while(ptr != nullptr){
            nodes.push_back(ptr->val);
            ptr = ptr->next;
        }
        
        // sorted list
        // mathworks technical round question --> construct height balanced BST
        
        return constructTree(nodes, 0, nodes.size() -1 );
    }
};