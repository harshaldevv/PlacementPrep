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
    int findMax(TreeNode* root){
        while(root->right != nullptr){
            root = root->right;
        }
        
        return root->val;
    }
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root == nullptr){
            return nullptr;
        }

        if(root->val > key){
            // go left
            root->left = deleteNode(root->left, key);
        }
        else if(root->val < key){
            root->right = deleteNode(root->right, key);
        }
        else{
            // found the key 
            
            // Both child exist
            if( root->left != nullptr && root->right != nullptr){
                int maxInLeftSubtree = findMax(root->left); // go right right in rootLeft
                cout << maxInLeftSubtree << endl;
                root->val = maxInLeftSubtree;
                root->left = deleteNode(root->left, maxInLeftSubtree);
            }
            else if(root->left != nullptr){
                // only left child exist
                return root->left;
            }
            else if(root->right != nullptr){
                // only right child exist
                return root->right;
            }
            else{
                // no child
                return nullptr;
            }
        }
        
        return root;
    }
};