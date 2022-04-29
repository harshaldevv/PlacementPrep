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
    int numComponents(ListNode* head, vector<int>& nums) {
        unordered_set<int> s (nums.begin(), nums.end());
        
        ListNode *curr = head;
        long ans = 0;
        // count "tail" of connected components
        
        while(curr != nullptr){
            if(s.count(curr->val) &&(curr->next == nullptr || !s.count(curr->next->val) )){
                ans++;
            }
            curr = curr->next;
        }
        
        return ans;
    }
};