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
        
        
        // Attempt 2
        vector<int> v(2, -1);
        
        if(head == nullptr || head->next == nullptr){
            return v;
        }
        
        int criticalPointsCount = 0;
        
        int firstCriticalPoint = -1;
        int prevCriticalPoint = -1;
        int currCriticalPoint = -1;
        
        
        
        ListNode *prev = head;
        ListNode *curr = head->next;
        int index = 1;
        
        int minDiff = INT_MAX;
        
        while(curr != nullptr){
            index++; //index incrementer
            ListNode *nxt = curr->next;
            
            if(nxt == nullptr){
                break;
            }
            
            if( (curr->val < prev->val && curr-> val < nxt->val) || (curr->val > prev->val && curr->val > nxt->val)   ){
                criticalPointsCount++;
                //local min  or local max
                if(firstCriticalPoint == -1){
                    firstCriticalPoint = index;
                    prevCriticalPoint = index;
                }
                else{
                    currCriticalPoint = index;
                    
                    minDiff =  min(minDiff, currCriticalPoint - prevCriticalPoint);
                    
                    prevCriticalPoint = currCriticalPoint;
                    
                }
                
            }
            
            prev = curr;
            curr = curr->next;
        }
        
        if(criticalPointsCount < 2){
            return v; // v = [-1, -1]
        }
        
        // v[0] -->  min-Dist;
        v[0] = minDiff;
        
        v[1] =  currCriticalPoint - firstCriticalPoint;
        
        return v;
        
        
        ///-----------------------------
        
        //Attempt 1;  --> O(N) TC, O(N) SC
        
//         vector<int> v(2, -1);
        
//         if(head == nullptr || head->next == nullptr){
//             return v;
//         }
        
//         int criticalPointsCount = 0;
//         vector<int> criticalPointsData;
        
        
        
//         ListNode *prev = head;
//         ListNode *curr = head->next;
//         int index = 1;
        
//         while(curr != nullptr){
//             index++; //index incrementer
//             ListNode *nxt = curr->next;
            
//             if(nxt == nullptr){
//                 break;
//             }
            
//             if( (curr->val < prev->val && curr-> val < nxt->val) || (curr->val > prev->val && curr->val > nxt->val)   ){
//                 //local min  or local max
//                 criticalPointsCount++;
//                 criticalPointsData.push_back(index);
//             }
            
//             prev = curr;
//             curr = curr->next;
//         }
        
//         if(criticalPointsCount < 2){
//             return v; // v = [-1, -1]
//         }
        
//         v[0] = INT_MAX; // min-Dist;
//         for(int i = 0 ; i < criticalPointsData.size() -1 ; i++){
//             v[0] = min(v[0], criticalPointsData[i+1] - criticalPointsData[i] );
//         }
        
        
//         v[1] =  criticalPointsData.back() - criticalPointsData.front() ;//max-Dist
        
//         return v;
    }
};