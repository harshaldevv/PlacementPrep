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
    ListNode* insertionSortList(ListNode* head) {
        if(head == nullptr || head->next == nullptr){
            return head;
        }
        
        ListNode *dummy = new ListNode (INT_MIN);
        dummy->next = head;
        
        ListNode *curr = head;
        while(curr != nullptr){
            if(curr->next != nullptr && curr->val > curr->next->val){
                
                // out or order node 
                ListNode *outOfOrder = curr->next;
                
                //find insertionSpot;
                ListNode *preInsertionNode;
                ListNode *cursor = dummy;
                
                while(cursor->val < outOfOrder->val){
                    preInsertionNode = cursor;
                    cursor = cursor->next;
                }
                
                ListNode *nxt = curr->next->next;
                
                preInsertionNode->next = outOfOrder;
                outOfOrder->next = cursor;
                curr->next = nxt;
                
                // curr = nxt;
                
            }
            else{
                
                curr = curr->next;
                
            }
        }
        
        return dummy->next;
        
    }
};