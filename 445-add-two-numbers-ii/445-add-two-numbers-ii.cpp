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
    ListNode *reverseLL(ListNode *p){
        ListNode *prev = nullptr;
        ListNode *curr = p;
        ListNode *nxt = p->next;
        
        while(curr != NULL){
            nxt = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nxt;
            
        }
        
        return prev;
    }
    
    
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        
        ListNode *dummy = new ListNode(-1);
        ListNode *temp = dummy;
        
        l1 = reverseLL(l1);
        l2 = reverseLL(l2);
        
        ListNode *p1 = l1;
        ListNode *p2 = l2;
        int carry = 0;
        
        while(p1 || p2 || carry){
            int sum = 0;
            if(p1 != nullptr){
                sum += p1->val;
            }
            if (p2 != nullptr){
                sum += p2->val;
            }
            
            sum+=carry;
            
            carry = sum/10;
            sum%=10;
            
            temp->next = new ListNode(sum);
            temp = temp->next;
            
            if(p1!= nullptr){
                p1 = p1->next;
            }
            if(p2 != nullptr){
                p2 = p2->next;
            }
            
        }
        
        return reverseLL(dummy->next);
        
        
    }
};