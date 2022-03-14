class Solution {
    vector<int> getNGRIndex(vector<int>& nums, int n){
        vector<int> ans;
        stack<pair<int, int>> st;  // temp, index
        
        for(int i = n-1; i >= 0 ; i--){
            while(!st.empty() && st.top().first <= nums[i]){
                st.pop();
            }
            if(st.empty()){
                ans.push_back(-1);
            }
            else{
                ans.push_back(st.top().second);
            }
            
            st.push({nums[i], i});
        }
        
        
        
        // cout << "Before Reversal " << endl;
        // for(int i = 0 ; i < n ; i++){
        //     cout << ans[i] << " " ;
        // }
        
        // reverse
        reverse(ans.begin(), ans.end());
        
        // cout << endl;
        // cout << "After Reversal " << endl;
        // for(int i = 0 ; i < n ; i++){
        //     cout << ans[i] << " " ;
        // }
        
        
        return ans;
        
    }
    
    
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        
        // get NSR index
        
        vector<int> right = getNGRIndex(temperatures, temperatures.size());
        
        
        // jahan bhi -1 hoga wahan toh 0 kar dena ngr array
        // else arr[i] = arr[i] - i
        for(int i = 0 ; i < right.size() ; i++){
            if(right[i] == -1){
                right[i] = 0;
            }
            else{
                right[i] = right[i] - i;
            }
        }
        
        return right;
        
        
    }
};