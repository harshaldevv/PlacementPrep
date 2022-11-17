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
    int countLeftHeight(TreeNode * root){
        if(root == nullptr){
            return 0;
        }
        // recursive way --> iterative way bhi likhunga, it wont take up stack space
        
        // return 1 + countLeftHeight(root->left); // keep going left
        
        int h = 0;
        while(root){
            h++;
            root = root->left;
        }
        
        return h;
        
    }
    
    int countRightHeight(TreeNode *root){
        if(root == nullptr){
            return 0;
        }
        // recursive way --> iterative way bhi likhunga, it wont take up stack space
        
        // return 1 + countRightHeight(root->right); // keep going right
        
        int h = 0;
        while(root){
            h++;
            root = root->right;
        }
        
        return h;
        
    }
    int countNodes(TreeNode* root) {
//         if(root == nullptr){
//             return 0;
//         }
        
//         int lh = countLeftHeight(root);
//         int rh = countRightHeight(root);
        
//         if(lh == rh){
//             return (int)pow(2,lh) -1;
            
//         }
        
//         return 1 + countNodes(root->left) + countNodes(root->right);
        
        
        //17 Nov'22
        
        if(!root){
            return 0;
        }
        
        
        int counter = 0;
        
        queue<TreeNode*>q;
        
        q.push(root);
        
        
        while(!q.empty()){
            int sz = q.size();
            
            counter += sz;
            
            while(sz--){
                auto front = q.front();
                q.pop();
                
                if(front->left){
                    q.push(front->left);
                }
                
                if(front->right){
                    q.push(front->right);
                }
                
            }
        }
        
        return counter;
        
        
    }
};