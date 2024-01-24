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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        
        if(!list1){
            return list2;
        }
        
        if(!list2){
            return list1;
        }
        
        ListNode* dummyHead = new ListNode(-1);
        ListNode* ptr = dummyHead;
        
        ListNode* p1 = list1;
        ListNode* p2 = list2;
        
        while(p1 && p2){
            
            if(p1->val <= p2->val){
                ptr->next = p1;
                p1 = p1->next;
            }
            else{
                ptr->next = p2;
                p2 = p2->next;
            }
            ptr = ptr->next;
            
        }
        
        if(!p1){
            ptr->next = p2;
        }
        
        if(!p2){
            ptr->next = p1;
        }
        
        return dummyHead->next;
        
        
        
    }
};