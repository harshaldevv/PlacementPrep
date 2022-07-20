class Solution {
public:
    vector<int> NSL(vector<int> &nums){
        // NSL --> 
        // go i = 0 to n;
        // smaller hai toh ">=" use karlo
        int n = nums.size();
        
        vector<int> v(n);
        stack<pair<int, int>> st;
        for(int i = 0 ; i  < n ; i++){
            while(!st.empty() && st.top().first >= nums[i]){
                st.pop();
            }
            
            if(st.empty()){
                v[i] = -1;
            }
            else{
                v[i] = st.top().second;
            }
            
            st.push({nums[i], i});
        }
        
        
        return v;
        
    }
    
    vector<int> NSR(vector<int> &nums){
        
        int n = nums.size();
        
        stack<pair<int, int>> st;
        vector<int> v(n);
        
        for(int i = n-1 ; i  >= 0 ; i--){
            while(!st.empty() && st.top().first >= nums[i]){
                st.pop();
            }
            
            if(st.empty()){
                // v[i] = -1;
                v[i] = n;
            }
            else{
                v[i] = st.top().second;
            }
            
            st.push({nums[i], i});
        }
        
        return v;
        
        
    }
    int largestRectangleArea(vector<int>& heights) {
        
        int n = heights.size();
        // NSL, NSR index
        
        vector<int> left = NSL(heights);
        vector<int> right = NSR(heights);
        
        
        vector<int> width(n);
        
        vector<int> area(n);
        int maxArea = 0;
        
        for(int i = 0 ; i < n ; i++){
            width[i] = (right[i] - left[i]) - 1;
            
            area[i] = width[i] * heights[i];
            maxArea = max(maxArea, area[i]);
        }
        
        return maxArea;
        
    }
};