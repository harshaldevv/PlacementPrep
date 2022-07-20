class Solution {
public:
    void printArr(vector<int> &nums){
        cout << "v = ";
        
        for(auto & x : nums){
            cout << x << ", " ;
        }
        
        cout << endl;
        
        return ;
    }
    vector<int> NSL(vector<int> nums){
        
        int n = nums.size();
        
        vector<int> v(n);
        stack<pair<int, int> > st;
        
        for(int i = 0 ; i < n ; i++){
            while(!st.empty() && st.top().first >= nums[i] ){
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
    
    
    
    vector<int> NSR(vector<int> nums){
        
        int n = nums.size();
        vector<int> v(n);
        stack<pair<int, int> > st;
        
        for(int i = n-1 ; i >= 0 ; i--){
            while(!st.empty() && st.top().first >= nums[i] ){
                st.pop();
            }
            
            if(st.empty()){
                v[i] = n;
            }
            else{
                v[i] = st.top().second;
            }
            
            st.push({nums[i], i});
        }
        
        return v;
    }
    
    int MAH(vector<int> height){
        
        int n = height.size();
        
        vector<int> left = NSL(height);
        // cout << "hjeree" << endl;
        
        vector<int> right = NSR(height);
        // cout << "NSR" << endl;
        
        
        vector<int> width(n);
        vector<int> area(n);
        
        int maxAREA = 0;
        
        for(int i = 0 ; i < n ; i++){
            width[i] = right[i] - left[i] -1;
            
            area[i] = width[i]*height[i];
            
            maxAREA = max(maxAREA, area[i]);
        }
        
        return maxAREA;
        
    }
    int maximalRectangle(vector<vector<char>>& matrix) {
        
        // maximum area histogram in a binary matrix 
        
        // MAH --> NSL, NSR indexes and then width[] and then area[] , then max area from area[]
        
        
        // copy first row in a vector
        
        int m = matrix.size();
        int n = matrix[0].size();
        
        vector<int> building(n, 0);
        // printArr(building);
        
        int maxArea = 0;
        
        for(int i = 0 ; i < m ; i++){
            for(int j = 0 ; j < n ; j++){
                
                if(matrix[i][j] == '0'){
                    building[j] = 0;
                }
                else{
                    building[j] += 1;
                }
            }
            
            // printArr(building);
            
            // send this building vector in the MAH function
            
            int maxAreaInThisHisotgram = MAH(building);
            
            maxArea = max(maxArea, maxAreaInThisHisotgram);
            
        }
        
        return maxArea;
        
    }
};