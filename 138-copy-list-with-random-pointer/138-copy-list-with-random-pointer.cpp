/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        
        if(head == nullptr){
            return nullptr;
        }
        
        Node *curr = head;
        
        while(curr != nullptr){
            Node *t = new Node(curr->val);
            t->next = curr->next;
            curr->next = t;
            curr = curr->next->next;
        }
        
        // return head->next;
        
        curr = head;
        while(curr != nullptr){
            Node *t = curr->next;
            Node *rand = curr->random;
            
            if(rand != nullptr){
                t->random = rand->next;
            }
            else{
                t->random = nullptr;
            }
            
            
            curr = curr->next->next;
        }
        
        // reweaving the list
        
        Node *answer = head->next;
        
        Node *clonedList = head->next;
        curr = head;
        
        while(curr != nullptr){
            curr->next = curr->next->next;
            
            if(clonedList->next != nullptr){
                clonedList->next = clonedList->next->next;
                clonedList =  clonedList->next;
            }
            else{
                clonedList->next =  nullptr;
            }
            
            curr = curr->next;
        }
        
        
        return answer;
        
    }
};