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
    ListNode* swapPairs(ListNode* head) {
        ListNode *dummy = new ListNode(-1);
        dummy->next = head;
        
        ListNode *prev = dummy;
        ListNode *curr = head;
        
        while(curr != NULL && curr->next != nullptr){
            ListNode *nxt = curr->next;
            
            prev->next = nxt;
            curr->next = nxt->next;
            nxt->next = curr;
            
            prev = curr;
            curr = curr->next;
        }
        
        return dummy->next;
        
    }
};