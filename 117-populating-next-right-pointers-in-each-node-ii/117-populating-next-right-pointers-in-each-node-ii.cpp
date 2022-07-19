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
        
        // Level order traversal TC O(n) but with O(1) space
        
        // queue<TreeNode*> q;
        
        Node *p = root;
        
        while(p){
        
            Node *nextLevel = NULL;
            
            if(p->left){
                nextLevel = p->left;
            }
            else if(p->right){
                nextLevel = p->right;
            }
            
            
            
            while(p){
                
                Node *runner = NULL;

                if(p->left){
                    
                    //check if nextLevel is null 
                    // if it is initalise the nextlevel with this "p" child
                    if(nextLevel == NULL){
                        nextLevel = p->left;
                    }
                    
                    if(p->right){
                        p->left->next = p->right;
                    }
                    else{
                        // now basically find a node such that it has either of its child
                        // Node *runner = p->next;
                        runner = p->next;
                        while(runner != nullptr){
                            if(runner->left != nullptr || runner->right != nullptr){
                                break;
                            }
                            runner = runner->next;
                        }

                        if(runner != nullptr && runner->left){
                            p->left->next = runner->left;
                        }
                        else if (runner != nullptr && runner->right) {
                            p->left->next = runner->right;
                        }
                        
                    }
                }
                
                if(p->right){
                    
                    //check if nextLevel is null 
                    // if it is initalise the nextlevel with this "p" child
                    if(nextLevel == NULL){
                        nextLevel = p->right;
                    }
                    
                    if(runner == NULL){
                        // find that node jiska koi left ya right child ho
                        // now basically find a node such that it has either of its child
                        // Node *runner = p->next;
                        Node* runner2 = p->next;
                        // cout << "runner2 --> " << runner2->val << endl;
                        while(runner2 != nullptr){
                            if(runner2->left != nullptr || runner2->right != nullptr){
                                // cout << "runner2 = " << runner2->val << endl;
                                break;
                            }
                            runner2 = runner2->next;
                        }

                        if( runner2 != nullptr && runner2->left){
                            p->right->next = runner2->left;
                        }
                        else if ( runner2 != nullptr && runner2->right ){
                            p->right->next = runner2->right;
                        }
                    }
                    else{
                        // runner null nahi tha
                        Node *runner2 = runner;
                        
                        while(runner2 != nullptr){
                            if(runner2->left != nullptr || runner2->right != nullptr){
                                break;
                            }
                            runner2 = runner2->next;
                        }

                        if( runner2 != nullptr && runner2->left){
                            p->right->next = runner2->left;
                        }
                        else if ( runner2 != nullptr && runner2->right ){
                            p->right->next = runner2->right;
                        }   
                    }
                }
                
                
                p = p->next;
            
        
            }
            if(nextLevel == nullptr){
                break;
            }
            
            p = nextLevel;
        }
        
        
        return root;
        
    }
};