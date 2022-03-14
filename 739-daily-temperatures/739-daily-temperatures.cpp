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
        
        
        
        // reverse
        reverse(ans.begin(), ans.end());
        
        
        return ans;
        
    }
    
    
    vector<int> onePassSoln(vector<int>& nums, int n){
        // basically find NGR_index and then do ngr[i] = ngr[i] - i
        // end me reverse kr dena dhyan se lul
        
        vector<int> ans;
        stack<pair<int,int>> st;
        
        for(int i = n-1; i >= 0 ; i--){
            while(!st.empty() && st.top().first <= nums[i]){
                st.pop();
            }
            if(st.empty()){
                ans.push_back(0);
            }
            else{
                ans.push_back(st.top().second - i);
            }
            st.push({nums[i], i});
        }
        
        //reverse
        
        reverse(ans.begin(), ans.end());
        
        return ans;
    }
    
    
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        
        // one pass soln
        
        return onePassSoln(temperatures, temperatures.size());
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        // my below soln is 2 pass , however it can be made into one pass
        
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