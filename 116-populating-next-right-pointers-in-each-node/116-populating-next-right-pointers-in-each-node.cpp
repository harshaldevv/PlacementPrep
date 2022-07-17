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
        
        // TC - O(n)
        // SC - O(1)
        
        Node *p = root;
        
        while(p ){
            Node *nextLevel = p->left;
            if(nextLevel == nullptr){
                // it means we have are "p" at the last level
                // and we've connected the last level 
                // therefore just break
                break;
                
            }
            
            while(p){
                
                p->left->next = p->right;
                
                if(p->next){
                    p->right->next = p->next->left;
                }
                else{
                    // p->next= null hai,
                    // therefore kuch mat karo abhi
                    ;
                }
                
                p = p->next;
            }
            p = nextLevel;
        }
        
        return root;
    }
};