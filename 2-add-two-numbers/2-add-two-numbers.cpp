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
    
    int length (ListNode *head){
        int l = 0;
        while(head !=NULL){
            l++;
            head = head->next;
        }
        return l;
    }
    
    ListNode *reverseLL(ListNode *head){
        ListNode *curr = head;
        ListNode *prev = NULL;
        
        while(curr != NULL){
            ListNode *nxt = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nxt;
        }
        
        return prev;
    }
    
    
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        
        
        ListNode *dummy = new ListNode(-1);
        
        ListNode *pt = dummy;
        
        int sum = 0;
        int carry = 0;
        
        ListNode *p1 = l1;
        ListNode *p2 = l2;
        
        
        while(p1 || p2 || carry){
            sum = 0;
            if(p1!= NULL){
                sum += p1->val;
            }
            
            if(p2!= NULL){
                sum += p2->val;
            }
            sum +=  carry;
            
            cout << "sum = " << sum << endl;
            
            carry = sum/10;
            cout << "carry = " << carry << endl;
            
            pt->next = new ListNode(sum%10);
            cout << "sum%10 = " << sum%10 << endl;
            
            pt = pt->next;
            
            if(p1 != NULL){
                p1 = p1->next;
            }
            
            if(p2!= NULL){
                p2 = p2->next;
            }
        }
        
        // return reverseLL(dummy->next);  --> reverse me ans nahi chahiye inko
        
        // therefore
        return dummy->next;
        
        
        
        
    }
};