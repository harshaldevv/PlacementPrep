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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        
        if(l1 == nullptr){
            return l2;
        }
        if(l2 == nullptr){
            return l1;
        }
        
        ListNode *p1 = l1;
        ListNode *p2 = l2;
        
        ListNode *dummy = new ListNode(-1);
        ListNode* cursor = dummy;
        
        int sum = 0;
        int carry = 0;
        
        while ( p1 || p2 || carry){
            
            sum = 0;
            
            sum+= carry;
            carry = 0;
            if(p1 != nullptr){
                sum += p1->val;
            }
            
            if( p2 != nullptr){
                sum += p2->val;
            }
            
            if(sum >= 10){
                carry = sum/10;
                sum%= 10;
            }
            
            ListNode *temp = new ListNode(sum);
            cursor->next = temp;
            cursor = cursor->next;
            
            if(p1 != nullptr){
                p1 = p1->next;
            }
            
            if(p2 != nullptr ){
                p2 = p2->next;
            }
            
        }
        
        return dummy->next;
    }
};