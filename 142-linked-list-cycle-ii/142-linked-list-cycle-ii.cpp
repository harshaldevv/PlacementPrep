/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        
        if(head == nullptr || head->next == nullptr){
            return nullptr;
        }
        
        ListNode *slow = head;
        ListNode *fast = head;
        
        bool cycle = false;
        while(fast != nullptr && fast->next != nullptr){
            slow = slow->next;
            fast = fast->next->next;
            
            if(slow == fast){
                cycle = true;
                break;
            }
        }
        
        if(!cycle){
            return nullptr;
        }
        
        fast = head;
        
        while(slow != fast){
            slow = slow->next;
            fast = fast->next;
        }
        
        return fast;
        
    }
};