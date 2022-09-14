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
#define ppl pair<int, pair<int, ListNode*>> 
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        
        ListNode *dummy = new ListNode(-1);
        
        ListNode *ptr = dummy;
        
        
        // min heap
        
        priority_queue<ppl, vector<ppl> , greater<ppl>> pq;
        
        for(int i = 0 ; i < lists.size() ; i++){
            if(lists[i] != nullptr ){
                auto t = lists[i];
                cout << "t  val = " << t->val << endl;
                pq.push({t->val , {i, t}});
            }
        }
        
        while(!pq.empty()){
            auto top = pq.top();
            pq.pop();
            
            int e = top.first;
            int i = top.second.first;
            auto pointerrr = top.second.second;
            
            ptr->next = new ListNode(e);
            ptr = ptr->next;
            
            if(pointerrr->next != nullptr){
                pq.push({pointerrr->next->val, {i, pointerrr->next}});
            }
        }
        
        return dummy->next;
        
    }
};