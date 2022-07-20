class Solution {
public:
    
    void printArr(vector<int> &nums){
        cout << "v = " ;
        for(auto &x : nums){
            cout << x << ", " ;
        }
        
        cout << endl;
        
        return ;
    }
    
    vector<int> maximumLeft(vector<int> &nums){
    
        int n = nums.size();
        vector<int> v(n);
        
        v[0] = nums[0];
        
        for(int i = 1 ; i < n ; i++){
            v[i] = max(v[i-1], nums[i]);
        }
        
        return v;
    }
    
    vector<int> maximumRight(vector<int> &nums){
    
        int n = nums.size();
        vector<int> v(n);
        
        v[n-1] = nums[n-1];
        
        for(int i = n-2 ; i >=0  ; i--){
            v[i] = max(v[i+1], nums[i]);
        }
        
        return v;
    }
    
    int trap(vector<int>& height) {
        
        int n = height.size();
        
        // FGL --> Farthest Greater Left
        // FGR --> Farthest Greater Right
        
        // printArr(height);
        
        vector<int> FGL = maximumLeft(height);
        vector<int> FGR = maximumRight(height);
        
        // printArr(FGL);
        // printArr(FGR);
        
        int totalWater = 0 ;
        
        for(int i = 0 ; i < n ; i++){
            totalWater += ( min(FGL[i], FGR[i]) - height[i] );
        }
        
        return totalWater;
    }
};