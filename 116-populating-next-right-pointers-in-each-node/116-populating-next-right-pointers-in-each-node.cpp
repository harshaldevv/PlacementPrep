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
        
        // code from the populate next pointer 2
        // this is also => SC - O(1), TC - O(N)
        
        Node* parent = root;
        Node* child = nullptr;
        Node *childHead = nullptr;
        
        
        while(parent){
            
            while(parent){
                
                if(parent->left){
                    if(childHead == nullptr){
                        childHead = parent->left;
                    }
                    else{
                        child->next = parent->left;
                    }
                    child = parent->left;
                }
                
                if(parent->right){
                    if(childHead == nullptr){
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
            childHead = nullptr;
            child = nullptr;
        }
        
        
        return root;
        
        
    }
};