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
        
        ListNode* t = head;
        
        for(int i = 0 ; i < n ; i++){
            t = t->next;
        }
        
        // If fast pointer becomes null, remove the first node
        if (!t) {
            return head->next;
        }
        
        ListNode * x= head;
        
        while(t->next ){
            t = t->next;
            x = x->next;
        }
        
        
        
        x->next = x->next->next;
        
        
        return head;
        
    }
};