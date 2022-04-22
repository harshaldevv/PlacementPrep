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
        
        ListNode *temp = head;
        
        for(int i = 0 ; i < k ; i++){
            if(temp == NULL){
                return head;
            }
            temp= temp->next;
        }
        
        ListNode *prev = nullptr;
        ListNode *curr = head;
        ListNode *nxt = nullptr;
        
        for(int i = 0 ; i < k ; i++){
            nxt = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nxt;
        }

        // 
        ListNode *ulta = reverseKGroup(temp, k);
        
        head->next = ulta;
        
        return prev;
        
    }
};