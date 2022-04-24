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
    ListNode* swapNodes(ListNode* head, int k) {
        
        // 
        
        ListNode *dummy = new ListNode(-1);
        dummy->next = head;
        
        ListNode *left = head;
        ListNode *curr = head;
        ListNode *right = head;
        
        // ListNode *sdash = dummy;
        // ListNode *fdash = dummy;
        
        
        for(int i = 1 ; i <k ;i++){
            left = left->next;
            curr = curr->next;
            
            // sdash = sdash->next;
            
        }
        
        while(curr->next != NULL){
            right = right->next;
            curr = curr->next;
            
            // fdash = fdash->next;
        }
        
//         ListNode *t1 = left->next;
//         ListNode *t2 = right->next;
        
//         sdash->next = right;
//         right->next = t1;
//         fdash->next = left;
//         left->next = t2;
        
        cout << left->val << " , " << right->val << endl;
        swap(left->val, right->val);
        
        return dummy->next;;
        
        
        //swapping
        
        
    }
};