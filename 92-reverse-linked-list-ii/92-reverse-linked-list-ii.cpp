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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        
        ListNode *dummy = new ListNode (-1);
        dummy->next = head;
        
        ListNode *curr = head;
        ListNode *leftprev = dummy;
        
        for(int i = 1 ; i < left ; i++){
            curr = curr->next;
            leftprev = leftprev->next;
        }
        
        ListNode *LEFT = curr;
        
        leftprev->next = nullptr;
        
        
        ListNode *prev = nullptr;
        for(int i = left ; i <= right ; i++){
            
            ListNode *nxt = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nxt;
            
        }
        
        leftprev->next = prev;
        
        LEFT->next = curr;
        
        return dummy->next;
        
        
    }
};