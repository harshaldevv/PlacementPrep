class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        
        
        // way 2 --> aditya verma NGR solution VARIATION
        
        int n = nums.size();
        vector<int> ans;
        stack<int> st;
        
        for(int i = n-1 ; i>= 0 ; i--){
            st.push(nums[i]);
        }
        
        for(int i = n-1 ;i >= 0 ; i--){
            while(!st.empty() && st.top() <= nums[i]){
                st.pop();
            }
            
            if(st.empty()){
                ans.push_back(-1);
            }
            else{
                ans.push_back(st.top());
            }
            
            st.push(nums[i]);
        }
        
        reverse(ans.begin(), ans.end());
        
        return ans;
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
//         // Way 1 --> array ko khol do, aka circular of size n 
//         // toh kholke size 2n ki ho jayega
//         // ispe NGR inkal do 2n wali array pe  (dont forget to reverse NGR array too)
//         // uske baad copy the first n elements from this NGR array 
//         // and you will get the resultant vector
        
//         int n = nums.size();
        
//         int size = 2*n -1;
        
//         vector<int> copy(size, -1);
        
//         for(int i = 0 ; i < size ; i++){
//             copy[i] = nums[i%n];
//         }
        
//         vector<int> ans;
//         stack<int> st;
        
//         for(int i = copy.size() -1; i>= 0 ; i--){
//             while(!st.empty() && st.top() <= copy[i]){
//                 st.pop();
//             }
            
//             if(st.empty()){
//                 ans.push_back(-1);
//             }
//             else{
//                 ans.push_back(st.top());
//             }
            
//             st.push(copy[i]);
//         }
        
//         reverse(ans.begin(), ans.end());
        
//         // now get the first n elements of this ans array
        
//         vector<int> finalAns;
        
//         for(int i = 0 ; i < n ; i++){
//             finalAns.push_back(ans[i]);
//         }
        
//         return finalAns;
        
    }
};