/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    void helper(Node * root){
        
        // TC - O(n)
        // SC - O(1) --> ignoring right now the recursive stack O(n)
        
        if(root == nullptr){
            return ;
        }
        
        if(root->left == nullptr && root->right == nullptr){
            // leaf node
            return ;
        }
        
        
        root->left->next = root->right;
        
        helper(root->left);
        helper(root->right);
        
        return ;
        
    }
    
    void connectInnerNodes(Node* root){
        
        // T(n) = 2* T(n/2) + O(n) --> at every node, we go left and right, so basically
        // we are taking only the n/2 nodes.  --> recurrence is similar to merge sort
        // Also for a particular node, we are doing O(n) work 
        
        //after solving, we get TC - O(nlogn)
        // SC - O(1) --> if we ignore recursive stack of O(n)
        
        if(root == nullptr){
            return ;
        }
        
        
        if(root->left == nullptr && root->right == nullptr){
            // leaf node
            return ;
        }
        
        
        Node *p = root->left;
        Node *q = root->right;
        
        // cout << p->val << " , " << q->val << endl;
        
        p->next = q;
        
        while(p->right && q->left){
            p->right->next = q->left;
            p = p->right;
            q = q->left;
        }
        
        connectInnerNodes(root->left);
        connectInnerNodes(root->right);
        
        return ;
        
    }
    
    Node* connect(Node* root) {
        
        if(root == nullptr){
            return nullptr;
        }
        
        
        // level order traversal approach was TC - O(n), SC - O(n)
        
        // now optimally doing Tc - O(n), SC - O(1)
        
        
        
        // basically this code of mine will work in T(n) = O(nlogn) , SC - O(1) [recursive stack = O(n)]

        helper(root); // --> takes O(n) time
        
        cout << "chal gaya helper" << endl;
        // connectInnerNodes(root->left, root->right);
        
        connectInnerNodes(root);// --> takes TC - O(nlogn)
        
        
        return root;
    
    }
};