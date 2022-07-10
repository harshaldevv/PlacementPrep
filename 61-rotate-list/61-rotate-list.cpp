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
    int lengthLL(ListNode *head){
        int l = 0;
        
        while(head != nullptr){
            l++;
            head = head->next;
        }
        return l;
    }
    ListNode* rotateRight(ListNode* head, int k) {
        if(head == nullptr || k ==0){
            return head;
        }
        int l = lengthLL(head);
        
        // cout << "l = " << l << endl;
        
        if(k >= l){
            k = k%l;
        }
        
        if(k == 0){
            return head;
        }
        
        cout << "k,l " << k << " , " << l << endl;
        
        ListNode *ptr = head;
        
        for(int i = 1 ; i < (l - k) ;i++){
            ptr = ptr->next;
        }
        
        ListNode *temp = ptr->next;
        ptr->next = nullptr;
        
        ListNode *temp2 = temp;
        
        while(temp2->next != nullptr){
            temp2 = temp2->next;
        }
        
        temp2->next = head;
        
        return temp;
        
        
        
    }
};