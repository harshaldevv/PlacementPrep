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
    ListNode* reverseKGroup(ListNode* head, int k) {
        
        int l = 0;
        
        ListNode *temp = head;
        
        //getting length
        while(temp != NULL){
            l++;
            temp = temp->next;
        }
        
                
        ListNode *dummy = new ListNode(-1);
        dummy->next = head;
        
        if(k>l){
            return head;
        }

        int groups = l/k;
        
        ListNode *before = dummy;
        ListNode *after = head;
        
        ListNode *curr = nullptr;
        ListNode *prev = nullptr;
        ListNode *nxt = nullptr;
        
        for(int i = 0 ; i < groups ; i++){
            curr = after;
            prev = before;
            for(int j = 0 ; j < k ; j++){
                // do reversal
                nxt = curr->next;
                curr->next = prev;
                prev = curr;
                curr = nxt;
            }
            after->next = curr;
            before->next = prev;
            before = after;
            after = curr;

        }
        
        return dummy->next;
        
    }
};