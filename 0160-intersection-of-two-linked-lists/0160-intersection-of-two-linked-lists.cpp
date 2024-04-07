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
    ListNode* f(ListNode* p, ListNode* q, int l1, int l2){
        int x = l1-l2;
        
        ListNode *ptr1 = p;
        ListNode *ptr2 = q;
        
        while(x--){
            ptr1 = ptr1->next;
        }
        
        while(ptr1){
            if(ptr1 == ptr2){
                return ptr1;
            }
            
            ptr1 = ptr1->next;
            ptr2 = ptr2->next;
        }
        
        return nullptr;
    }
    
    int length(ListNode *p){
        int l = 1;
        while(p){
            l++;
            p = p->next;
        }
        
        return l;
    }
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        
        if(headA == nullptr || headB == nullptr){
            return nullptr;
        }
        
        int l1 = length(headA);
        int l2 = length(headB);
        
        if(l2 > l1 ){
            return f(headB, headA, l2, l1);
        }
        else{
            return f(headA, headB, l1, l2);
        }
        
        
        
    }
};