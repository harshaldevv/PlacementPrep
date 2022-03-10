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
    vector<int> nextLargerNodes(ListNode* head) {
        
        vector<int> arr;
        
        ListNode *ptr = head;
        
        while(ptr != NULL){
            arr.push_back(ptr->val);
            ptr = ptr->next;
        }
        
        // now do NGR on arr;
        
        stack<int> st;
        vector<int> ans;
        int n = arr.size();
        for(int i = n-1; i>= 0 ;i--){
            while(!st.empty() && st.top() <= arr[i]){
                st.pop();
            }
            if(st.empty()){
                ans.push_back(0);
            }
            else{
                ans.push_back(st.top());
            }
            st.push(arr[i]);
        }
        
        reverse(ans.begin(), ans.end());
        
        return ans;
        
    }
};