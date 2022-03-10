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
        
        // 2ptr approach
        int n = height.size();
        
        int l = 0;
        int r = n-1;
        
        int maxL = 0;
        int maxR = 0;
        
        int totalWater = 0;
        
        // while(l<r){
        //     if(height[l] < height[r]){
        //         maxL = max(height[l], maxL);
        //         totalWater += (maxL - height[l]);
        //         l++;
        //     }
        //     else{
        //         maxR = max(height[r], maxR);
        //         totalWater += (maxR - height[r]);
        //         r--;
        //     }
        // }
        
        
        
        // either of these 2 two ptr approaches work 
        
        
        
        
        while(l<=r){
            
            if(height[l] > maxL){
                maxL = height[l];
            }
            
            if(height[r] > maxR){
                maxR = height[r];
            }
            
            if(height[l] < height[r]){ // taking minium of either of the building
                totalWater += (abs(maxL - height[l]));
                l++;
            }
            else{
                totalWater += abs(maxR - height[r]);
                r--;
            }
        }
        
        return totalWater;
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
//         vector<int> maxL = maximumLeft(height);
//         vector<int> maxR = maximumRight(height);
        
//         int n = height.size();
        
        
//         int totalWater = 0;
//         for(int i = 0 ; i < n ; i++){
//             totalWater += ( min(maxR[i], maxL[i]) - height[i]);
//         }
        
//         return totalWater;
        
    }
};