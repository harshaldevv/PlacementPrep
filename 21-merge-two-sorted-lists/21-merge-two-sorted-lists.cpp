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
        
        if(list1 == nullptr && list2 == nullptr){
            return nullptr;
        }
        
        if(list1 == nullptr){
            return list2;
        }
        if(list2 == nullptr){
            return list1;
        }
        
        
        ListNode *newHead;
        ListNode *newTail;
        
        if(list1->val <=  list2->val){
            newHead = list1;
            newTail = list1;
            list1 = list1->next;
        }
        else{
            newHead = list2;
            newTail = list2;
            list2 = list2->next;
        }
        
        //got our newHead;
        
        
        
        while(list1 != NULL && list2 != NULL){
            if(list1->val <= list2->val){
                newTail->next = list1;
                list1 = list1->next;
            }
            else{
                newTail->next = list2;
                list2 = list2->next;
            }
            newTail = newTail->next;
            
        }
        
        if(list1 == nullptr){
            //attach the remaining list 2
            newTail->next = list2;
        }
        
        
        if(list2 == nullptr){
            //attach the remaining of list1
            newTail->next = list1;
        }
        
        return newHead;
        
    }
};