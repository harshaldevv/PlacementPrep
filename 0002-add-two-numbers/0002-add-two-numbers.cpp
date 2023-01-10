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
        
        ListNode *p1 = l1;
        ListNode *p2 = l2;
        ListNode *dummy = new ListNode (-1);
        ListNode *tail = dummy;
        int carry = 0;
        int sum = 0;
        while(p1 || p2 || carry){
            sum += carry;
            
            if(p1){
                sum += p1->val;
                p1 = p1->next;
            }
            
            if(p2){
                sum += p2->val;
                p2 = p2->next;
            }
            
            carry = sum/10;
            
            sum%= 10;
            ListNode *temp = new ListNode(sum);
            tail->next = temp;
            tail = tail->next;
            
            sum = 0;
        }
        return dummy->next;
        
    }
};