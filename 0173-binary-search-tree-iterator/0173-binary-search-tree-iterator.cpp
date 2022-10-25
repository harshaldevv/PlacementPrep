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
class BSTIterator {
public:
    stack<TreeNode*> st;
    
    BSTIterator(TreeNode* root) {    
        while(!st.empty()){
            st.pop();
        }
        pushAll(root);
    }
    
    int next() {
        if(hasNext()){
            auto temp = st.top();
            st.pop();
            if(temp->right){
                pushAll(temp->right);
            }
            return temp->val;
        }
        
        return -1;
        
    }
    
    bool hasNext() {
        
        return !st.empty();
        
    }
    void pushAll(TreeNode * root){
        if(root == nullptr){
            return ;
        }
        
        while(root){
            st.push(root);
            root = root->left;
        }
        
        return ;
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */