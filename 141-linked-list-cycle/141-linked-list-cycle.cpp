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
    bool hasCycle(ListNode *head) {
        
        bool cycleFound = false;
        
        ListNode* slow = head;
        ListNode *fast = head;
        
        while(fast && fast->next){
            slow = slow->next;
            fast = fast->next->next;
            
            if(slow == fast){
                cycleFound = true;
                break;
            }
        }
        
        return cycleFound;
        
    }
};