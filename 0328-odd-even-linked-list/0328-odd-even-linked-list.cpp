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
    ListNode* oddEvenList(ListNode* head) {
        if(!head || head->next == nullptr){
            return head;
        }
        
        // ListNode* dummy = new ListNode(-1);
        // dummy->next = head
        
        
        ListNode* oddHead = new ListNode(-1);
        ListNode* evenHead = new ListNode(-1);
        
        ListNode* oddTail = oddHead;
        ListNode* evenTail = evenHead;
        
        bool isOdd= true;
        ListNode* ptr = head;
        
        while(ptr){
            if(isOdd){
                oddTail->next = ptr;
                oddTail = oddTail->next;
            }
            else{
                evenTail->next = ptr;
                evenTail = evenTail->next;
                
            }
            
            isOdd = !isOdd;
            ptr = ptr->next;
        }
        
    
        oddTail->next = evenHead->next;
        evenTail->next = nullptr;
        
        
        return oddHead->next;
        
    }
};