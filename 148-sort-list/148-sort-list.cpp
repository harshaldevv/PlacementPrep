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
    ListNode *getMiddle(ListNode* head){
        if(head == NULL || head->next == NULL){
            return head;
        }
        
        ListNode *prev = NULL;
        ListNode *slow = head;
        ListNode *fast = head;
        
        while(fast!= NULL && fast->next != NULL){
            prev = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        
        return prev;
    }
    
    ListNode *merge(ListNode* l1, ListNode *l2){
        
        if(l1 == nullptr && l2 == nullptr){
            return nullptr;
        }
        
        if(l1 == nullptr){
            return l2;
        }
        if(l2 == nullptr){
            return l1;
        }
        
        ListNode *newHead;
        ListNode *newTail;
        
        if(l1->val < l2->val){
            newHead = l1;
            newTail = l1;
            l1 = l1->next;
        }
        else{
            newHead = l2;
            newTail = l2;
            l2 = l2->next;
        }
        
        while(l1 != nullptr && l2 != nullptr){
            if(l1->val <= l2->val){
                newTail->next = l1;
                newTail = newTail->next;
                l1 = l1->next;
            }
            else{
                newTail->next = l2;
                newTail = newTail->next;
                l2 = l2->next;
            }
        }
        
        if(l1 == nullptr){
            newTail->next = l2;
        }
        else if(l2 == nullptr){
            newTail->next = l1;
        }

        return newHead;
    }
    
    ListNode* sortList(ListNode* head) {
        if(head == nullptr || head->next == nullptr){
            return head;
        }
        
        //getting middle
        ListNode *mid = getMiddle(head);
        
        ListNode *secondListHead = mid->next;
        mid->next = nullptr;
        
        ListNode *l1 = sortList(head);
        ListNode *l2 = sortList(secondListHead);
        return merge(l1, l2);
        
        
        
    }
};