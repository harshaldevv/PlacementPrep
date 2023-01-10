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
        
        ListNode *curr = head;
        ListNode *dummy = new ListNode (-1);
        dummy->next = head;
        ListNode *before = dummy;
        
        while(curr && curr->next){
            ListNode *temp = curr->next;
            ListNode *after = curr->next->next;
            
            curr->next = after;
            temp->next = curr;
            
            before->next = temp;
            before = curr;
            
            curr = after;
            
        }
        
        return dummy->next;
        
    }
};