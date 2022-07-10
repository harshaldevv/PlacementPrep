/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if(list1 == nullptr){
            return list2;
        }
        if(list2 == nullptr){
            return list1;
        }
        
        ListNode *p = list1;
        ListNode *q = list2;
        
        ListNode *newHead, *newTail;
        
        if(p->val <= q->val){
            newHead = p;
            newTail = p;
            p = p->next;
        }
        else{
            newHead = q;
            newTail = q;
            q = q->next;
        }
        
        while( p != nullptr && q!= nullptr){
            if(p->val <= q->val){
                newTail->next = p;
                newTail = newTail->next;
                p = p->next;
            }
            else{
                newTail->next = q;
                newTail = newTail->next;
                q = q->next;
            }
        }
        
        if( p != nullptr ){
            newTail->next = p;
        }
        else if( q != nullptr ){
            newTail->next = q;
        }
        
        return newHead;
        
        
    }
};