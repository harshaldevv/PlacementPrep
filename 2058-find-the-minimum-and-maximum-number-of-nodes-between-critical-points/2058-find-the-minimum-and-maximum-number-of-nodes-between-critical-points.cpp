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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        
        vector<int> v(2,-1);

        if(head == nullptr || head->next == nullptr){
            return v;
        }
        
        ListNode *prev = head;
        ListNode *curr = head->next;
        
        int index = 0;
        int criticalPointsCount = 0;
        vector<int> criticalPointIndex;
        
        while(curr != nullptr){
            index++;
            
            ListNode *nxt = curr->next;
            
            if(nxt == nullptr){
                break;
            }
            
            if(curr->val < prev->val && curr-> val < nxt->val){
                //local min
                criticalPointsCount++;
                criticalPointIndex.push_back(index);  
            }
            else if(curr->val > prev->val && curr->val > nxt->val){
                //local max
                criticalPointsCount++;
                criticalPointIndex.push_back(index);
            }
            
            prev = curr;
            curr = curr->next;
        }
        
        
        if(criticalPointsCount < 2){
            return v; // v = [-1, -1]
        }
        
        // v[0] --> min_dist;
        // v[1] --> max_dist
        
        v[0] = INT_MAX;
        for(int i = 0 ; i < criticalPointIndex.size() -1 ; i++){
            v[0] = min(v[0], criticalPointIndex[i+1] - criticalPointIndex[i]);
        }
        
        v[1] = criticalPointIndex.back() - criticalPointIndex.front();  
        //max dist will always be b/w the first and the last critical point
        
        return v;
        
    }
};