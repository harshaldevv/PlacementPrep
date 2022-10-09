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
            return nullptr;
        }
        
        Node* p = root;
        
        while(p){
            Node* nextLevel = p->left;
            
            if(nextLevel == nullptr){
                // we've done our job of linking
                break;
            }
            else{
                
                while(p){    
                    p->left->next = p->right;
                    
                    if(p->next){
                        p->right->next = p->next->left;
                    }
                    else{
                        // do nothing
                        ;
                    }
                    p = p->next;
                }
            }
            p = nextLevel;
        }
        
        
        return root;
        
        
    }
};