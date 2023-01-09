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
    ListNode* deleteDuplicates(ListNode* head) {
        
        ListNode* dummy = new ListNode(-1);
        
        dummy->next = head;
        
        ListNode *prev = dummy;
        ListNode *curr = head;
        
        while(curr){
            while(curr->next && curr->val == curr->next->val){
                //skip duplicates
                curr = curr->next;
            }
            
            if(prev->next != curr){
                // jumping over duplicates
                prev->next = curr->next;
                curr = prev->next;
            }
            else{
                prev = prev->next;
                curr = curr->next;
            }
        }

        
        return dummy->next;
        
        
    }
};