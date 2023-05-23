class Solution {
public:
    vector<int> NSL(vector<int> &nums){
        int n = nums.size();
        vector<int> v(n, -1);
        stack<vector<int>> st;
        for(int i = 0 ; i < n ; i++){
            while(!st.empty() && st.top()[0] >= nums[i]){
                st.pop();
            }
            
            if(st.empty()){
                v[i] = -1;
            }
            else{
                v[i] = st.top()[1];
            }
            
            st.push({nums[i], i});
        }
        
        return v;
    }
    
    
    vector<int> NSR(vector<int> &nums){
        int n = nums.size();
        vector<int> v(n, -1);
        stack<vector<int>> st;
        for(int i = n-1 ; i >=0  ; i-- ){
            
            while(!st.empty() && st.top()[0] >= nums[i]){
                st.pop();
            }
            
            if(st.empty()){
                v[i] = n;
            }
            else{
                v[i] = st.top()[1];
            }
            
            st.push({nums[i], i});
        }
        
        return v;
    }
    
    
    int largestRectangleArea(vector<int>& heights) {
        
        int n = heights.size();
        
        vector<int> left = NSL(heights);
        
        vector<int> right = NSR(heights);


        
        int ans = INT_MIN;
        
        for(int i = 0 ; i < n ; i++){
            int width = right[i] - left[i] -1 ;
            int temp = width*heights[i];
            ans = max(ans, temp);
        }
        
        return ans;
        
    }
};