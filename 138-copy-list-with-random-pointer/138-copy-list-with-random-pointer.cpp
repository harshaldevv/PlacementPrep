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
            return head;
        }
        Node *ptr = head;
        
        while(ptr != nullptr){
            
            Node *cloned = new Node(ptr->val);
            Node *temp = ptr->next;
            
            ptr->next = cloned;
            cloned->next = temp;
            
            ptr = temp;
        }
        
        // return head;
        
        
        Node *original = head;
        
        while(original != nullptr){
            Node *cloned   = original->next;
            
            Node *rndm = original->random;
            
            Node *rndm_dash = nullptr ; // randm_dash is to be paired with cloned
            
            if(rndm != nullptr){
                rndm_dash = rndm ->next;
            }
            
            
            cloned->random = rndm_dash;
            
            original = original -> next ->next;
            
        }
        
        // return head;
        
        Node *cloned = head->next;
        Node *temp = head;
        
        Node *newHead = cloned;
        
        while(cloned != nullptr){
            
            Node *p = cloned->next;
            if(p == nullptr){
                // we've reach the end of our Linked List
                temp->next = p; // and p == nullptr
                return newHead;
            }
            
            Node *q = p->next;
            cloned->next = q;
            temp->next = p;
            
            cloned = cloned->next;
            temp = temp->next;
        }
        
        return newHead;
    }
};