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
        
        int sum = 0;
        int c = 0;
        
        ListNode* p1 = l1;
        
        ListNode *p2 = l2;
        
        
        ListNode *dummy = new ListNode (-1);
        ListNode *temp = dummy;
        
        while(p1 || p2 || c){
            sum = 0;
            
            if(p1){
                sum += p1->val;
            }
            
            if(p2){
                sum += p2->val;
            }
            
            sum += c;
            c = 0;
            
            c = sum/10;
            sum %=10;
            
            temp->next = new ListNode (sum);
            temp = temp->next;
            
            if(p1){
                p1 = p1->next;
            }
            if(p2){
                p2 = p2->next;
            }
        }
        
        return dummy->next;
        
    }
};