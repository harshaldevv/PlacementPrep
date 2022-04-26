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
    int pairSum(ListNode* head) {
        
        //why isnt vector thing working bitch
        
        vector<long> v;
        
        while(head != nullptr){
            v.push_back(head->val);
            head = head->next;
        }
        
        int n = v.size();
        long sum = 0;
        for(int i = 0 ; i <n/2 ; i++){
            if(v[i]+ v[n-i-1] > sum){
                sum = v[i]+ v[n-i-1];
            }
        }
        
        
        return sum;
    }
};