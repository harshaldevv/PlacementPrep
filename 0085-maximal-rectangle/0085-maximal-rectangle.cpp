class Solution {
public:
    vector<int> NSL(vector<int> &nums){
        int n = nums.size();
        
//         >= , 0, to n
        vector<int> v(n, 0);
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
        vector<int> v(n, n);
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
    
    
    int MAH(vector<int> &nums){
        
        vector<int> left = NSL(nums);
        vector<int> right = NSR(nums);
        
        int ans = INT_MIN;
        for(int i = 0 ; i < nums.size() ; i++){
            int width = right[i] - left[i] - 1;
            int temp = width * nums[i];
            ans = max(ans, temp);
        }
        
        return ans;
        
    }
    int maximalRectangle(vector<vector<char>>& matrix) {
        
        int n = matrix[0].size();
        vector<int> h(n, 0);
        
        int ans = INT_MIN;
        for(int i = 0 ; i < matrix.size() ; i++){
            for(int j = 0 ; j < matrix[0].size() ; j++){
                if(matrix[i][j] == '0'){
                    h[j] = 0;
                }
                else{
                    
                    h[j] += 1;
                }
            }
            
            
            int temp = MAH(h);

            ans = max(temp, ans);
            
        }
        
        return ans;
        
    }
};