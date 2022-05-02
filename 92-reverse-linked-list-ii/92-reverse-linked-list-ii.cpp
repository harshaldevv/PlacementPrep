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
        
        ListNode* leftPrev = nullptr;
        ListNode *left_;
        ListNode *rightPrev;
        ListNode* rightNext = nullptr;
        ListNode *right_;
        ListNode *curr = head;
        
        for(int i = 1 ; i <= right ; i++){
            if(i== left-1){
                leftPrev = curr;
            }
            if(i==left){
                left_ = curr;
            }
            if(i==right-1){
                rightPrev = curr;
            }
            if(i== right){
                right_ = curr;
                rightNext = curr->next;
            }
            
            curr = curr->next;
        }
        
//         cout << "leftPrev = " << leftPrev->val <<endl;
//         cout << "left_ = " << left_->val <<endl;
//         cout << "rightPrev = " << rightPrev->val << endl;
//         cout << "right_ = " << right_->val << endl;
//         cout << "rightNext = " << rightNext->val << endl;
        
        
        
        ListNode *prev = leftPrev;
        curr = left_;
        
        for(int i = 0 ; i <right- left +1 ; i++){
            ListNode *nxt = curr->next;
            
            curr->next = prev;
            prev = curr;
            curr = nxt;
            
        }
        
        // cout << "prev = " << prev->val << endl;
        // cout << "leftPrev = " << leftPrev->val <<endl;
        // cout << "right_ = " << right_->val << endl;
        
        if(left != 1){
            leftPrev->next = prev;
        }
        else{
            head = prev;
        }
        
        left_->next = rightNext;
        
        return head;
        
    }
};