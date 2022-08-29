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
        
        ListNode *newHead = nullptr;
        ListNode *newTail = nullptr;
        
        ListNode *p1 = list1;
        ListNode *p2 = list2;
        
        if(p1 == nullptr){
            return p2;
        }
        
        if(p2 == nullptr){
            return p1;
        }
        
        if(p1 ->val <= p2->val){
            newHead = p1;
            newTail = p1;
            p1 = p1->next;
        }
        else{
            newHead = p2;
            newTail = p2;
            p2 = p2->next;
        }
        
        while(p1 && p2){
            if(p1->val <= p2->val){
                newTail->next = p1;
                newTail = newTail->next;
                p1 = p1->next;
            }
            else{
                newTail->next = p2;
                newTail = newTail->next;
                p2 = p2->next;
                
            }
        }
        
        if(p1){
            newTail->next = p1;
        }
        
        if(p2){
            newTail->next = p2;
        }
        
        return newHead;
        
        
    }
};