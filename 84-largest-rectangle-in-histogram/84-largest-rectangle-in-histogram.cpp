class Solution {
public:
    
    vector<int> NSL(vector<int> &nums, int n){
        vector<int> v;
        stack<pair<int, int>> st;  // pair -> first == height, second == index
        
        int pseudoIndex = -1;
        
        for(int i = 0 ; i < n ; i++){
            while(!st.empty() && st.top().first >= nums[i]){
                st.pop();
            }
            
            if(st.empty()){
                v.push_back(pseudoIndex);
            }
            else{
                v.push_back(st.top().second);
            }
            
            st.push({nums[i], i});
        }
        
        return v;
    }
    
    vector<int> NSR(vector<int> &nums, int n){
        vector<int> ans;
        stack<pair<int, int>> st;
        int pseudoIndex = n;
        
        for(int i = n-1; i >= 0 ; i--){
            while(!st.empty() && st.top().first >= nums[i]){
                st.pop();
            }
            
            if(st.empty()){
                ans.push_back(pseudoIndex);
            }
            else{
                ans.push_back(st.top().second);
            }
            
            st.push({nums[i], i});
        }
        
        reverse(ans.begin(), ans.end());
        
        return ans;
    }
    
    int largestRectangleArea(vector<int>& heights) {
    
        int n = heights.size();
        
        vector<int> right = NSR(heights, n);
        vector<int> left = NSL(heights, n);
        
        int area;
        int maxArea = INT_MIN;
        for(int i = 0 ; i < n ; i++){
            //cout << right[i] << " , " <<left[i] << " " << " , h =  " << heights[i] << endl;
            int width = (right[i] - left[i] -1);
            area = heights[i] * width ;
            maxArea = max(area, maxArea);
        }
        
        return maxArea;
        
    }
};