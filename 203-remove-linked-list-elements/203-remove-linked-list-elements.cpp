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
    ListNode* removeElements(ListNode* head, int val) {
        
        //base cases
        if(head == nullptr){
            return nullptr;
        }
        
        if(head->val == val && head->next == nullptr){
            return nullptr;
        }
        
        
        //recursive calss
        if(head->val == val){
            return removeElements(head->next, val);
        }
        else{
            head->next = removeElements(head->next, val);
            return head;
        }
        
    }
};