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
    int getLength(ListNode *head){
        int l = 0;
        ListNode *curr = head;
        while(curr){
            l++;
            curr = curr->next;
        }
        
        return l;
    }
    
    ListNode* rotateRight(ListNode* head, int k) {
        
        if(!head || k == 0){
            return head;
        }
        
        ListNode *p1 = head;
        
        int len = getLength(head);
        k = k%len;

        if(k == 0){
            return head;
        }
        
        for(int i = 1 ; i < len-k ; i++){
            p1 = p1->next;
        }

        ListNode *p2 = p1->next;
        ListNode *newHead = p2;

        p1->next = NULL;

        //travel to the end of p2

        while(p2 && p2->next ){
            p2 = p2->next;
        }

        p2->next = head;
        
        return newHead;
    
    }
};