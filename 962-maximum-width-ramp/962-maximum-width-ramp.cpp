class Solution {
public:
    int maxWidthRamp(vector<int>& nums) {
        
        // vector<int> ans;
        int n = nums.size();
        int maxWidth = 0;
        
//         for(int i = 0 ; i < n ; i++){
//             for(int j = i + 1 ; j < n ; j++){
//                 if(nums[i] > nums[j]){
//                     continue;
//                 }
//                 maxWidth = max( maxWidth ,  j-i    );
                
//             }
//         }
        
        stack<pair<int, int>> st;
        
        for(int i = 0; i < n ; i++){
            if(st.empty() || nums[i] < st.top().first){
                st.push({nums[i], i});
            }
        }
        
        for(int i = n-1; i >=0 ; i--){
            while(!st.empty() && nums[i] >= st.top().first){
                maxWidth = max( maxWidth, i - st.top().second);
                st.pop();
            }
        }
        
        return maxWidth;
    }
};