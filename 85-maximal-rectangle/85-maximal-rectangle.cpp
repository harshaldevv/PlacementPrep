class Solution {
    vector<int> NSR(vector<int> &arr){
        vector<int> ans;
        int pseudoIndex = arr.size();
        stack<pair<int, int>> st;  //first price, second i
        
        for(int i = arr.size() -1. ; i >=0 ; i--){
            while(!st.empty() && st.top().first >= arr[i]){
                st.pop();
            }
            
            if(st.empty()){
                ans.push_back(pseudoIndex);
            }
            else{
                ans.push_back(st.top().second);
            }
            
            st.push({arr[i], i});
        }
        
        reverse(ans.begin(), ans.end());
        return ans;
    }
    
    
    
    
    vector<int> NSL(vector<int> &arr){
        vector<int> ans;
        int pseudoIndex = -1;
        stack<pair<int, int>> st;  //first price, second i
        
        for(int i = 0 ; i < arr.size() ;i++){
            while(!st.empty() && st.top().first >= arr[i]){
                st.pop();
            }
            
            if(st.empty()){
                ans.push_back(pseudoIndex);
            }
            else{
                ans.push_back(st.top().second);
            }
            
            st.push({arr[i], i});
        }
        
        
        return ans;
    
        
    }
    
    int MAH(vector<int> &buildings){
        
        vector<int> right = NSR(buildings);
        vector<int> left = NSL(buildings);
        
        int area = 0;
        int maxArea = -1;
        
        for(int i = 0 ; i < right.size() ;i++){
            area = buildings[i] * (right[i] - left[i] -1);
            maxArea = max(area, maxArea);
        }
        
        return maxArea;
        
    }
    
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        int rows = matrix.size();
        int cols = matrix[0].size();
        
        
        vector<int> buildings(cols);
        //copying first row in the building arr
        for(int i = 0 ; i < cols ;i++){
            if(matrix[0][i] == '0'){
                buildings[i] = 0;
            }
            else{
                buildings[i] = 1;
            }
            
        }
        
        int maxArea = INT_MIN;
        maxArea = MAH(buildings);
        
        
        
        
        cout << "maxArea = " << maxArea << endl;
        
        for(int i = 1 ; i < rows ;i++){
            for(int j = 0 ; j < matrix[i].size() ;j++){
                if(matrix[i][j] == '0'){
                    buildings[j] = 0;
                }
                else{
                    buildings[j] += 1;
                } 
            }
            
            maxArea = max(maxArea, MAH(buildings));
        }
        
        return maxArea;
    }
};