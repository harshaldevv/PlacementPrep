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
    ListNode* removeElements(ListNode* head, int val) {
        if(head == nullptr){
            return head;
        }
        if(head->val == val && head->next == nullptr){
            head = head->next;
            return head;
        }
        
        ListNode *dummy = new ListNode (-1);
        dummy->next = head;
        ListNode *curr = head;
        ListNode *prev = dummy;
        
        while(curr != nullptr){
            if(curr->val == val){
                ListNode *nxt = curr->next;
                
                if(nxt != nullptr &&nxt->val == val){
                    curr = nxt;
                    continue;
                }
                
                
                prev->next = nxt;
        
                prev= curr;
                curr = nxt;
                continue;
            }
            
            
            
            prev = curr;
            curr = curr->next;
            
        }
        
        return dummy->next;
    }
    
};