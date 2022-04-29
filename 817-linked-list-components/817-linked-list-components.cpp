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
        
        
        
        // attempt 1 --> https://leetcode.com/problems/linked-list-components/discuss/123842/C%2B%2BJavaPython-Easy-and-Concise-Solution-with-Explanation
        
        // count "tail" of connected components  <-- VERY CLEVER IDEA
        
        // from comments (of TulakHord) , see below , why the "if" condn is working
        // To do this, we just need to count tails of red parts."
        // tail of red parts = the current node is in setG and the next is not in setG
        
        unordered_set<int> s (nums.begin(), nums.end());
        
        ListNode *curr = head;
        long ans = 0;
        
        
        while(curr != nullptr){
            if(s.count(curr->val) &&(curr->next == nullptr || !s.count(curr->next->val) )){
                ans++;
            }
            curr = curr->next;
        }
        
        return ans;
    }
};