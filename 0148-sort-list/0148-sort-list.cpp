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
    
    ListNode* getMiddle(ListNode *head){
        
        if(head == NULL || head->next == NULL){
            return head;
        }
        
        ListNode *slow = head;
        ListNode *fast = head;
        ListNode *prev = nullptr;
        
        while(fast && fast->next){
            prev = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        
        if(fast != nullptr){
            prev = prev->next;

        }
        
        return prev;
        
        
    }
    
    ListNode* merge(ListNode *l1, ListNode* l2){
        
        if(l1 == nullptr && l2 == nullptr){
            return nullptr;
        }
        if(l1 == nullptr){
            return l2;
        }
        if(l2 == nullptr){
            return l1;
        } 
        
        ListNode *head ;
        ListNode *headptr;
        
        if(l1->val <= l2->val){
            head = l1;
            headptr = head;
            l1 = l1->next;
        }
        else{
            head = l2;
            headptr = head;
            l2 = l2->next;
        }
        
        while(l1 && l2){
         if(l1->val <= l2->val){
                 headptr->next = l1;
                 headptr = headptr->next;
                 l1 = l1->next;
            }
            else{
                headptr->next = l2;
                headptr = headptr->next;
                l2 = l2->next;
            }
        }
        
        if(l1){
            headptr->next = l1;
            headptr = headptr->next;
            l1 = l1->next;
        }
        
        if(l2){
            headptr->next = l2;
            headptr = headptr->next;
            l2 = l2->next;
        }
        
        
        return head;
        
    }
    ListNode* sortList(ListNode* head) {
        
         if(head == nullptr || head->next == nullptr){
            return head;
        }
        
        
        ListNode* mid = getMiddle(head);
        
        cout << "mid = "<< mid->val << endl;

        ListNode *l1 = head;
        ListNode *l2 = mid->next;
        mid->next = nullptr;
        
        l1 = sortList(l1);
        l2 = sortList(l2);
        
        return merge(l1, l2);
        
        
        
    }
};