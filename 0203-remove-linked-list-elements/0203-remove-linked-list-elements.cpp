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
    ListNode* removeElements(ListNode* head, int val) {
        
        //hci research 
        
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode* curr = dummy;
        while(curr->next != NULL){
            if(curr->next->val == val){
                ListNode* temp = curr->next;
                curr->next = temp->next;
                delete temp;
            } else{
                curr = curr->next;
            }
        }
        return dummy->next;
    }
};
