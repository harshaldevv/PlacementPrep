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
        
        ListNode *dummy = new ListNode(-1);
        ListNode *tempPtr = dummy;
        
        //minheap
        // pair<int, ListNode*>
        priority_queue<pair<int, ListNode*>, vector<pair<int, ListNode*>>, greater<pair<int, ListNode*>>> pq;
        
        for(int i = 0 ; i < lists.size() ; i++){
            auto p = lists[i];
            if(p != nullptr){
                pq.push({p->val, p});    
            }
            
            // cout << "p val = " << p->val << endl;
        }
        
        while(!pq.empty()){
            auto top = pq.top();
            pq.pop();
            int e = top.first;
            ListNode* ptr = top.second;
            // cout << ptr->val << " " ;
            
            tempPtr->next = ptr;
            tempPtr = tempPtr->next;
            
            if(ptr->next){
                pq.push({ptr->next->val, ptr->next});
            }
        }
        
        return dummy->next;
    }
};