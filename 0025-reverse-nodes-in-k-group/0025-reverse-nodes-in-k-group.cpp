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
        
        if(head == NULL){
            return NULL;
        }
        
        ListNode *cursor = head;
        
        for(int i = 0 ; i < k ; i++){
            if(cursor == NULL){
                return head;
            }
            cursor = cursor->next;
        }
        
        //iska mtlb ye hai ki we have K nodes
        
        // now we need to reverse them
        
        ListNode *curr = head;
        ListNode *prev = nullptr;
        ListNode *nxt;
        
        for(int i = 0 ; i < k ; i++){
            nxt = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nxt;
        }
        
        head->next = reverseKGroup(curr, k);
        
        return prev;
   
    }
};