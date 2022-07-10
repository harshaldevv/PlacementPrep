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
    ListNode *reverseLL(ListNode* head){
        
        ListNode * prev = nullptr;
        ListNode *curr = head;
        ListNode *nxt;
        
        while(curr != nullptr){
            nxt = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nxt;
        }
        
        return prev;
    }
  
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(head == nullptr){
            return head;
        }
        
        
        ListNode *ptr = head;
        
        for(int i = 0 ; i < k ; i++){
            if(ptr != nullptr){
                ptr = ptr->next;
            }
            else{
                return head;
            }
        }
        
        ListNode* curr = head;
        ListNode *prev = nullptr;
        ListNode* nxt;
        
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