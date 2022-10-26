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
    Node* connect(Node* root) {
        
        if(root == nullptr){
            return root;
        }
        
        Node *parent = root ;
        Node *child = nullptr;
        Node *childHead = nullptr;
        
        while(parent){
            
            while(parent){
                // horizontal traversal
                
                if(parent->left){
                    if(!childHead){
                        childHead = parent->left;
                    }
                    else{
                        child->next = parent->left;
                    }
                    child = parent->left;
                }
                
                if(parent->right){
                    if(!childHead){
                        childHead = parent->right;
                    }
                    else{
                        child->next = parent->right;
                    }
                    child = parent->right;
                }
                
                parent = parent->next;
                
            }
            
            parent = childHead;
            
            childHead = NULL;
            child = NULL;
        }
        
        return root;
        
    }
};