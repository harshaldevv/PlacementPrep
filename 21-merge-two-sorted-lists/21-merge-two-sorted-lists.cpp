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
        
        if(list1 == NULL && list2 == NULL){
            return NULL;
        }
        
        if(list1 == NULL){
            return list2;
        }
        
        if(list2 == NULL){
            return list1;
        }
        
        //attempt 2 starts --> NO EXTRA SPACE 
        ListNode *start;
        ListNode *p1 = list1;
        ListNode *p2 = list2;
        
        if(p1->val < p2->val){
            start = p1;
            p1 = p1->next;
        }
        else{
            start = p2;
            p2 = p2->next;
        }
        
        ListNode *newHead = start;
        
        while(p1 != NULL && p2 != NULL){
            if(p1->val < p2->val){
                // kuch kuch karna 
                start->next = p1;
                start = start->next;
                p1 = p1->next;
            }
            else{
                // kuch aur karna hai 
                start->next = p2;
                start = start->next;
                p2 = p2->next;
            }
        }
        
        while (p1!= NULL){
            start->next = p1;
            start = start->next;
            p1 = p1->next;
        }
        
        while(p2 !=NULL){
            start->next = p2;
            start = start->next;
            p2 = p2->next;
        }
        
        return newHead;
        // attempt 2 ends
        
//         // attempt 1 -->using extra space
        
//         ListNode *dummy = new ListNode(-200);
//         ListNode *newHead = dummy;
        
//         ListNode *p1 = list1;
//         ListNode *p2 = list2;
        
//         while(p1!= NULL && p2!= NULL){
//             if(p1->val < p2->val){
//                 ListNode *temp = new ListNode(p1->val);
//                 newHead->next = temp;
//                 newHead = newHead->next;
//                 p1 = p1->next;
                
//             }
//             else{
//                 ListNode *temp = new ListNode(p2->val);
//                 newHead->next = temp;
//                 newHead = newHead->next;
//                 p2 = p2->next;
//             }  
//         }
        
//         while(p1!= NULL){
//             ListNode *temp = new ListNode(p1->val);
//             newHead->next = temp;
//             newHead = newHead->next;
//             p1 = p1->next;

//         }
        
//         while(p2 != NULL){
//             ListNode *temp = new ListNode(p2->val);
//             newHead->next = temp;
//             newHead = newHead->next;
//             p2 = p2->next;
//         }
//         newHead = dummy->next;
        
//         return newHead;
        
    }
};