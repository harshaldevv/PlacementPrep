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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        
        if(head == nullptr){
            return head;
        }
        
        ListNode *ptr = head;
        
        for(int i = 0 ; i < n ; i++){
            ptr = ptr->next;
        }
        
        if(ptr == nullptr){
            // it means we were asked to remove the first node
            return head->next;
        }
        
        ListNode* start = head;
        
        while(ptr->next){
            start = start->next;
            ptr = ptr->next;
        }
        
        start->next = start->next->next;
        
        
        return head;
        
    }
};