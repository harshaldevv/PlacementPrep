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
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        vector<ListNode*> v;
        
        if(k==1 ){
            v.push_back(head);
            return v;
        }
        
        if(head == nullptr){
            for(int i = 0 ; i < k ; i++){
                v.push_back(nullptr);
            }
            return v;
        }
        
        
        
        ListNode *curr = head;
        int l = 0;
        while(curr != nullptr){
            l++;
            curr = curr->next;
        }
        
        // cout << "l = " << l << endl;
        
        int elemsPerGroup = l/k;
        int remaining = l%k;
        
        curr = head;
        int i = 0;
        
        for(i = 0 ; i < k ; i++){
            
            ListNode *newHead = curr;
            ListNode *newTail = newHead;
            
            int loopKitnibar = elemsPerGroup;
            
            if(remaining > 0){
                loopKitnibar = elemsPerGroup+1;
                remaining--;
            }
            
            while(newTail != nullptr && loopKitnibar >1 ){
                newTail = newTail->next;
                loopKitnibar--;
            }
            ListNode *nxt;
            if(newTail != nullptr){
                nxt = newTail->next;
                newTail->next = nullptr;
            }
            else{
                nxt = newTail; //farzi kaam yahan, warna error when lastnode pe hotehai hum
            }
            
            
            v.push_back(newHead);
            
            curr = nxt;
            
        }
        
        return v;
        
        
        
    }
};