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
        ListNode *temp = head;
        while(temp != nullptr){
            l++;
            temp = temp->next;
        }
        
        return l;
    }
    ListNode* rotateRight(ListNode* head, int k) {
        if(head == nullptr){
            return head;
        }
        if(k==0){
            return head;
        }
        int l = getLength(head);
        
        cout << "l = " << l << endl;
        
        k = k%l;
        cout << "k = " << k << endl;
        
        if(k == 0){
            return head;
        }
        
        
        ListNode *p = head;
        for(int i = 1 ; i < l -  k ; i++){
            p = p->next;
        }
        
        cout << "p = " << p->val << endl;
        ListNode *temp = p->next;
        p->next =  nullptr;
        
        ListNode *temp2 = temp;
        while(temp2->next != nullptr){
            temp2 = temp2->next;
        }
        
        temp2->next = head;
        
        return temp;
        
    }
};