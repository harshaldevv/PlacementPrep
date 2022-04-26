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
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        
        ListNode *curr = list1;
        ListNode *t1, *t2;
        for(int i = 0 ; i < b +2 ; i ++){
            if(i== a-1){
                t1 = curr;
            }
            t2 = curr;
            curr = curr->next;
        }
        
        ListNode *temp  = list2;
        
        while(temp->next != nullptr){
            temp = temp->next;
        }
        
        t1->next = list2;
        temp->next = t2;
        
        
        return list1;
        
    }
};