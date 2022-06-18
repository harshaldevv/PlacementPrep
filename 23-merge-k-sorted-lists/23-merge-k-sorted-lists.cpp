#include <bits/stdc++.h> 
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
#define p pair<int, ListNode*>
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        
        priority_queue<p, vector<p>, greater<p> > pq;
        
        
        // min heap

        //         for(int i = 0 ; i < lists.size() ; i++){
//             ListNode* curr_list = lists[i]; // extracting current linked list
            
//             if(curr_list != NULL) // if element present in the linked list
//             {
//                 pq.push({curr_list -> val, curr_list}); // push into min heap
//             }
//         }
        
        for(auto x : lists){
            // cout << x << endl;
            if(x!= nullptr){ // if list is empty, then dont put it in minheap
                pq.push({x->val, x});
            }
            
        }
        
        ListNode* dummy = new ListNode(-1);
        
        ListNode *ptr = dummy;
        
        while(!pq.empty()){
            p front = pq.top();
            pq.pop();
            
            int x = front.first;
            
            ptr->next = new ListNode(x);
            ptr = ptr->next;
            
            if(front.second->next != nullptr){
                pq.push({front.second->next->val, front.second->next});
            }
        }
        
        return dummy->next;
        
    }
};