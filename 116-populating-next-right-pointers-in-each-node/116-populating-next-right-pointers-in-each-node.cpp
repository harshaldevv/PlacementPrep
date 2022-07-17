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
    
    void dfs(Node *curr, Node* nxt){
        // using the soln from discuss
        
        if(curr == nullptr){
            return ;
        }
        
        curr->next = nxt;
        dfs(curr->left, curr->right);
        
        if(curr->next == nullptr){
            dfs(curr->right, NULL);
        }
        else{
            dfs(curr->right, curr->next->left);
        }
        
        return ;
        
            
    }
    
    Node* connect(Node* root) {
        dfs(root, nullptr);
        return root;
    }
};