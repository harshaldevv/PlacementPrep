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
        
        bool cycleFound = false;
        
        ListNode* slow = head;
        ListNode *fast = head;
        
        while( fast && fast->next){
            slow = slow->next;
            fast = fast->next->next;
            
            if(slow == fast){
                cycleFound = true;
                break;
            }
        }
        
        if(!cycleFound){
            return nullptr;
        }
        
        fast = head;
        // Now move fast and slow one by one and where they meet is the starting point of our LL
        while( slow != fast){
            slow = slow->next;
            fast = fast->next;
        }
        
        return slow;
        
        
    }
};