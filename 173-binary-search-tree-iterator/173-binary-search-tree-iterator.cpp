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
    /*
    Approach:
        basically, we need to implement a inorder traversal.
        we are going to perform iterative DFS for that we need stack
        we are going to start from the root and keep pushing the left nodes to the stack

        next():
            we are going to pop the top element from the stack and return it
            if the popped element has a right child, we are going to push the right child to the stack
            if the popped element has no right child, we are going to return the popped element
        hasNext():
            if the stack is empty, return false
            else return true
    
    
    HELPFUL LINK = https://leetcode.com/problems/binary-search-tree-iterator/discuss/1965329/MAY-be-you-UNDERSTAND!!
    */
    
public:
    // TC - O(1) 
    // SC - O(H) 
    
    stack<TreeNode*> st;
    
    BSTIterator(TreeNode* root) {
        addAllLeft(root);
    }
    
    int next() {
        
        
        TreeNode* top = st.top();
        st.pop();
        addAllLeft(top->right);
        return top->val;
    }
    
    bool hasNext() {
        return !st.empty();
    }
    
    void addAllLeft(TreeNode* root){
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