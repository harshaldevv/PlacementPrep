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
        
        if(head == nullptr || head->next == nullptr || left == right){
            return head;
        }
        
        // one pass
        ListNode *dummy = new ListNode(-1);
        dummy->next = head;
        
        ListNode *leftPrev = dummy;
        ListNode *left_ = head;
        
        ListNode *curr = head;
        ListNode *prev;
        
        ListNode *leftNode;
        
        for(int i = 1 ; i <= right ; i++){
            if(i < left){
                leftPrev = curr;
                prev = leftPrev;
                
                left_ = left_->next;
                curr = curr->next;
            }
            else{
                // i >= left 
                // go from left to right. --> "right" tak jane ki tension for loop par hai
                ListNode *nxt = curr->next;
                curr->next = prev;
                prev = curr;
                curr = nxt;
            }
        }
        
        leftPrev->next = prev;
        left_->next = curr;
        
        
        return dummy->next;
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
//         // two pass solution , but O(1) space
//         // need to write cleaner code of two pass        
//         ListNode* leftPrev = nullptr;
//         ListNode *left_;
//         ListNode *rightPrev;
//         ListNode* rightNext = nullptr;
//         ListNode *right_;
//         ListNode *curr = head;
        
//         for(int i = 1 ; i <= right ; i++){
//             if(i== left-1){
//                 leftPrev = curr;
//             }
//             if(i==left){
//                 left_ = curr;
//             }
//             if(i==right-1){
//                 rightPrev = curr;
//             }
//             if(i== right){
//                 right_ = curr;
//                 rightNext = curr->next;
//             }
            
//             curr = curr->next;
//         }

        
//         ListNode *prev = leftPrev;
//         curr = left_;
        
//         //reversing the list
//         for(int i = 0 ; i <right- left +1 ; i++){
//             ListNode *nxt = curr->next;
//             curr->next = prev;
//             prev = curr;
//             curr = nxt;
            
//         }
        
        
//         if(left != 1){
//             leftPrev->next = prev;
//         }
//         else{
//             //if left == 1
//             head = prev;
//         }
        
//         left_->next = rightNext;
        
//         return head;
        
    }
};