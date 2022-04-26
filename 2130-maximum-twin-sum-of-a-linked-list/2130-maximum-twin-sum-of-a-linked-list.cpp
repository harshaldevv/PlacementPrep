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
    ListNode *reverseLL(ListNode *head){
        ListNode *curr = head;
        ListNode *prev = nullptr;
        ListNode *nxt;
        
        while(curr != nullptr){
            nxt = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nxt;
        }
        
        return prev;
    }
    int pairSum(ListNode* head) {
        
        if(head == nullptr){
            return 0;
        }
        
        //using the hint of reversing the ll
        
        int n = 0;
        
        ListNode *ptr = head;
        
        while(ptr != nullptr){
            n++;
            ptr = ptr->next;
        }
        
        ListNode *dummy = new ListNode(-1);
        dummy->next = head;
        
        ListNode *secondHead = head;
        ListNode *firstTail = dummy;
        
        
        for(int i = 0 ; i < n/2 ; i++){
            firstTail = firstTail->next;
            secondHead = secondHead->next;
        }
        
        ListNode *t1 = head;
        firstTail->next = nullptr;
        
        ListNode *t2 = reverseLL(secondHead);
        
        // now checking manually
        int sum = 0;
        while(t1 && t2){
            if(t1->val + t2->val > sum){
                sum = t1->val + t2->val;
            }
            t1 = t1->next;
            t2 = t2->next;
        }
        
        return sum;
        
        
        
        
    }
};