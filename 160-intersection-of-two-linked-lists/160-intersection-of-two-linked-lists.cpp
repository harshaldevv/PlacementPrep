/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    int getLength(ListNode *head){
        int l = 1;
        while(head->next != NULL){
            l++;
            head = head->next;
        }
        
        return l;
    }
    
    ListNode *intersection(ListNode *headA, ListNode *headB, int l1, int l2){
        // headA , l1 --> LinkedList with greater length
        
        int x = l1-l2;
        
        while(x--){
            headA = headA->next;
        }
        
        while(headA != NULL){
            if(headA == headB){
                return headA;
            }
            
            headA= headA->next;
            headB = headB->next;
            
        }
        
        return NULL;
    }
    
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        
        if(headA == nullptr || headB == nullptr){
            return nullptr;
        }
        
        ListNode *temp1 = headA;
        ListNode *temp2 = headB;
        
        int l1 = getLength(temp1);
        int l2 = getLength(temp2);
        cout << "l1 = " << l1 << "  , l2 = " << l2 << endl;
        
        if(l1 >= l2){
            return intersection(headA, headB, l1, l2);
            
        }
        else{
            return intersection(headB, headA, l2, l1);
            
        }
        
        
    }
};