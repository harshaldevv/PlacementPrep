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
    ListNode* reverseList(ListNode* head) {
        
        if(head == nullptr || head->next == nullptr){
            return head;
        }
        
        // prev = null
        // curr --> 1
        //  null.<------1       2---> 
        //                    nxt
        //           prev 
        //                    curr
            
        ListNode *curr = head;
        ListNode *prev = nullptr;
        ListNode *nxt ;
        
        while(curr != nullptr){
            nxt = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nxt;
        }
        
        return prev;
        
    }
};