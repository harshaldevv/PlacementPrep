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
        ListNode *curr = head;
        int l = 0;
        while(curr!= nullptr){
            l++;
            curr = curr->next;
        }
        return l;
    }
    
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        
        // now writing elegant code
        
        vector<ListNode*> v(k, nullptr);  //make vector of size k 
    
        
        ListNode *curr = head;
        ListNode *prev = nullptr;
        
        //calculate length
        int l = getLength(head);
        
        int elementsPerGroup = l/k;
        int remaining = l%k;
        
        for(int i = 0 ; i < k ; i++){
            v[i] = curr;
            
            // we gotta see now for how many elems this group will have
            int howManyTimesLoopWillRun = elementsPerGroup;
            
            if(remaining > 0){
                howManyTimesLoopWillRun++;
                remaining--;
            }
            
            for(int j = 0 ; j < howManyTimesLoopWillRun ; j++){
                prev = curr;
                curr = curr->next;
            }
            
            if(prev != nullptr){
                prev->next = nullptr;
            }
            
            
        }
        
        return v;
        
    }
};