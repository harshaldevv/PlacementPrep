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
    ListNode* rotateRight(ListNode* head, int k) {
        if(head == NULL || head->next == NULL || k == 0){
            return head;
        }
        
        // get length along with get to the lastNode;
        int length = 1;
        
        ListNode *temp = head;
        
        while(temp->next != NULL){
            length++;
            temp = temp->next;
        }
        
        k = k%length;
        
        if(k == 0){
            return head;
        }
        
        //got the lastNode;
        //circular linked list bana di
        temp->next = head;
        
        int x = 1;
        
        ListNode *tempAgain = head;
        
        while(x < length - k){
            tempAgain = tempAgain->next;
            x++;
        }
        
        ListNode *answer = tempAgain->next;
        
        tempAgain->next = NULL;
        
        return answer;
        
        
        
        
        
        
    }
};