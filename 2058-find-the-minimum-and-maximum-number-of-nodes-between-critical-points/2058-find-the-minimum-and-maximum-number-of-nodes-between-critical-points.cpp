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
        
        int firstCriticalPoint = -1;
        int prevCriticalPoint = -1;
        int currCriticalPoint = -1;
        
        int minDiff = INT_MAX;
        int maxDiff = INT_MIN;
        
        while(curr != nullptr){
            index++;
            
            ListNode *nxt = curr->next;
            
            if(nxt == nullptr){
                break;
            }
            
            if( (curr->val < prev->val && curr-> val < nxt->val) || (curr->val > prev->val && curr->val > nxt->val)   ){
                //local min  or local max
                criticalPointsCount++;
                
                if(firstCriticalPoint == -1){
                    firstCriticalPoint = index;
                    prevCriticalPoint = index;
                }
                else{
                    currCriticalPoint = index;
                    minDiff = min(minDiff, currCriticalPoint - prevCriticalPoint);
                    
                    //updating prevCriticalPoint
                    prevCriticalPoint = currCriticalPoint;
                }
            }

            prev = curr;
            curr = curr->next;
        }
        
        
        if(criticalPointsCount < 2){
            return v; // v = [-1, -1]
        }
        
        // v[0] --> min_dist;
        // v[1] --> max_dist
        
        v[0] = minDiff;
        
        v[1] = currCriticalPoint - firstCriticalPoint;
        
        
        return v;
        
    }
};