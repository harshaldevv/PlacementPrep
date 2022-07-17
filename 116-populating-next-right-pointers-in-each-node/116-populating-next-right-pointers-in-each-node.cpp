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
        
        // now doing Tc - O(n), SC - O(1)
        
        
        helper(root);
        
        cout << "chal gaya helper" << endl;
        // connectInnerNodes(root->left, root->right);
        
        connectInnerNodes(root);
        
        
        return root;
    
    }
};