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
    
    ListNode *getmid(ListNode *head){
        ListNode *slow = head;
        ListNode *fast = head;
        
        while(fast && fast->next){
            slow = slow->next;
            fast = fast->next->next;
        }
        
        return slow;
    }
    ListNode *reverseLL(ListNode* head){
        ListNode *curr = head;
        ListNode *prev = nullptr;
        ListNode *nxt;
        
        while(curr){
            nxt = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nxt;
        }
        
        return prev;
        
    }
    
    
    void reorderList(ListNode* head) {
        
        ListNode *mid = getmid(head);
        
        ListNode *aage = mid->next;
        
        mid->next = nullptr;
        
        
        ListNode *p1 = head;
        ListNode*p2 = reverseLL(aage);
        
        while(p1 && p2){
            
            ListNode *p1next = p1->next;
            
            p1->next = p2;
            
            p1 = p2;
            p2 = p1next;
            
        }
        return ;
    }
};