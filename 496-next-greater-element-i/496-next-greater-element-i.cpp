class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        
        // find NGRs of all elements of nums2 and push in a hashmap
        unordered_map<int, int> mp;
        
        int n = nums2.size();
        
        stack<int> st;
        
        for(int i = n-1 ; i >= 0 ; i--){
            while(!st.empty() && st.top() <= nums2[i]){
                st.pop();
            }
            
            if(st.empty()){
                mp[nums2[i]] = -1;
            }
            else{
                mp[nums2[i]] = st.top();
            }
            st.push(nums2[i]);
        }
        
        
        //make an answer vector
        vector<int> ans;
        
        // iterate over nums1, fetch the NGR for that element (nums1) and the push in answer vector
        for(int i = 0 ; i < nums1.size() ; i++){
            int x = mp[nums1[i]];
            ans.push_back(x);
        }
        return ans;
        
    }
};