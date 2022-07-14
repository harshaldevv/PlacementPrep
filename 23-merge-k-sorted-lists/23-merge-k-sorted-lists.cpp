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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        
        // min heap
        
        priority_queue<pair<int, ListNode*>, vector<pair<int, ListNode*>>, greater<pair<int, ListNode*>>> pq; // minheap
        
        for(auto &x : lists){
            if(x != nullptr){
                pq.push({x->val, x});
            }
        }
        
        
        ListNode *dummy = new ListNode(-1);
        ListNode *ptr = dummy;
        
        // iterate in the pq
        while(!pq.empty()){
            auto front = pq.top();
            pq.pop();
            
            int val = front.first;
            
            ListNode *temp = new ListNode(val);
            ptr->next = temp;
            ptr = ptr->next;
            
            if(front.second->next != nullptr){
                pq.push({front.second->next->val, front.second->next});
            }
        }
        
        
        return dummy->next;
        
    }
};