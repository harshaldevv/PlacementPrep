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
    
    ListNode *getMid(ListNode *head){
        ListNode *slow = head;
        ListNode *fast = head;
        
        while(fast && fast->next){
            slow = slow->next;
            fast = fast->next->next;
        }
        
        return slow;
    }
    
    ListNode *reverseLL(ListNode *head){
        ListNode *curr = head;
        ListNode *prev = nullptr;
        ListNode *nxt;
        
        while(curr){
            nxt = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nxt;
        }
        
        return prev;
    }
    
    void reorderList(ListNode* head) {
        
        // get mid
        // reverse beyond mid
        
        ListNode* mid = getMid(head);
        
        ListNode *temp = mid->next;
        mid->next = NULL;
        
        ListNode *rev = reverseLL(temp);
        
        
        ListNode *p1 = head;
        ListNode *p2 = rev;
        
        bool flag = true;
        while(p1 && p2){
            if(flag){
                //p1 turn
                ListNode *after = p1->next;
                p1->next = p2;
                p1 = after;
            }
            else{
                ListNode *after = p2->next;
                p2->next = p1;
                p2 = after;
            }
            
            flag = !flag;
        }
        
        return ;
        
    }
};