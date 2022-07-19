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
        // level order traversal se karte hai
        if(root == nullptr){
            return nullptr;
        }
        
        queue<Node*> q;
        
        q.push(root);
        
        while(!q.empty()){
            int sz = q.size();
            
            for(int i = 0 ; i < sz ; i++){
                
                auto front = q.front();
                q.pop();
                
                if( i != sz-1 ){
                    auto aagewala = q.front();
                    front->next = aagewala;
                }
                
                if(front->left){
                    q.push(front->left);
                }
                
                if(front->right){
                    q.push(front->right);
                }
            }
        }
        
        return root;
    }
};