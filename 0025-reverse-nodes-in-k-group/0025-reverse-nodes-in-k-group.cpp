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
        
        ListNode *dummy = new ListNode(-1);
        
        dummy->next = head;
        
        ListNode *peeche = dummy;
        ListNode *aage = head;
        
        
        ListNode *curr = aage;
        ListNode *prev = peeche;
        ListNode *nxt = nullptr;
        while(aage){
            ListNode *cursor = aage;
            for(int i = 0 ; i < k ; i++){
                if(cursor == NULL){
                    return dummy->next;
                }
                cursor = cursor->next;
            }
            
            //we have K nodes to reverse
            
            for(int i = 0 ; i < k ; i++){
                nxt = curr->next;
                curr->next = prev;
                prev = curr;
                curr = nxt;
            }
            
            aage->next = curr;
            peeche->next = prev;
            
            peeche = aage;
            aage = aage->next;
        }
        
        return dummy->next;
    }
};