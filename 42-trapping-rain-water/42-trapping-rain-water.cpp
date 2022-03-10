class Solution {
    
    vector<int> maximumLeft(vector<int> &arr){
        int n = arr.size();
        vector<int> ans(n);
        ans[0] = arr[0];
        
        for(int i = 1 ; i < n ; i++){
            ans[i] = max(ans[i-1], arr[i]);
        }
        
        return ans;
    }
    
    vector<int> maximumRight(vector<int> &arr){
        int n = arr.size();
        vector<int> ans(n);
        ans[n-1] = arr[n-1];
        
        for(int i = n-2 ; i >= 0 ; i--){
            ans[i] = max(ans[i+1], arr[i]);
        }
        
        return ans;
    }
    
    
    
public:
    int trap(vector<int>& height) {
        
        vector<int> maxL = maximumLeft(height);
        vector<int> maxR = maximumRight(height);
        int n = height.size();
        
//         cout << "left = ";
//         for(int i = 0 ; i < n ;i++){
//             cout << maxL[i] << " , ";
//         }
//         cout << endl;
        
//         cout << "right = " ;
//         for(int i = 0 ; i < n ;i++){
//             cout << maxR[i] << " , ";
//         }
//         cout << endl;
        
        
        int totalWater = 0;
        for(int i = 0 ; i < n ; i++){
            totalWater += (min(maxR[i], maxL[i]) - height[i]);
        }
        
        return totalWater;
        
    }
};