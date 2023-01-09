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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        
        ListNode *p1 = head;
        ListNode *dummy = new ListNode(-1);
        ListNode *prev = dummy;
        dummy->next = head;
        
        for(int k = 0 ; k < left-1 ; k++){
            p1 = p1->next;
            prev = prev->next;
        }
        // cout << "prev = " << prev->val << endl;
            
        prev->next = NULL;
        ListNode *TAIL = p1;
        
        ListNode* prevNode = nullptr;
        ListNode* currNode = p1;
        ListNode *nxtNode ;
        
        for(int k = left ; k <= right ; k++){
            nxtNode = currNode->next;
            currNode->next = prevNode;
            prevNode = currNode;
            currNode = nxtNode;
        }
        
//         while(currNode && currNode->val != right){
//             nxtNode = currNode->next;
//             currNode->next = prevNode;
//             prevNode = currNode;
//             currNode = nxtNode;
//         }
        
//         //do one more time;
        
//         nxtNode = currNode->next;
//         currNode->next = prevNode;
//         prevNode = currNode;
//         currNode = nxtNode;
        
        prev->next = prevNode;
        
        TAIL->next = currNode;
        
        return dummy->next;
        
        
        
    }
};