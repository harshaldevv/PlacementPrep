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
        if(!list1){
            return list2;
        }
        
        if(!list2){
            return list1;
        }
        
        ListNode *dummy = new ListNode(-1);
        
        ListNode* head;
        ListNode* tail;
        
        ListNode *p1 = list1;
        ListNode *p2 = list2;
        
        if(p1->val <= p2->val){
            head = p1;
            tail = p1;
            p1 = p1->next;
        }
        else{
            head = p2;
            tail = p2;
            p2 = p2->next;
        }
        
        while(p1  && p2 ){
            
            if(p1->val <= p2->val){
                tail->next = p1;
                tail = tail->next;
                p1 = p1->next;
            }
            else{
                tail->next = p2;
                tail = tail->next;
                p2 = p2->next;
            }
        }
        
        if(!p1){
            tail->next = p2;
        }
        
        if(!p2){
            tail->next = p1;
        }
        
        dummy->next = head;
        
        return dummy->next;
        
    }
};