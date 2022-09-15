class Solution {
public:
    
    int getPeak(vector<int> &nums){
        
        int n = nums.size();
        if(n==1){
            return 0;
        }
        
        int l = 0;
        int r = n-1;
        
        
        while(l<=r){
            int mid = l + (r-l)/2;
            
            if(mid !=  0  && mid != n-1){
                // mid belongs from 1 to n - 1
                int prev = nums[mid-1];
                int curr = nums[mid +1];
                
                if(nums[mid] > prev && nums[mid]  > curr){
                    return mid;
                }
                else if(nums[mid] > prev && nums[mid] < curr){
                    // go right
                    l = mid +1;
                }
                else{
                    r = mid -1;
                }
            }
            else if(mid == 0){
                if(nums[0] > nums[1]){
                    return 0;
                }
                else{
                    return 1;
                }
            }
            else if(mid == n-1){
                if(nums[n-1] > nums[n-2]){
                    return n-1;
                }
                else{
                    return n-2;
                }
            }
        }
        
        
        return -1;
        
    }
    int findPeakElement(vector<int>& nums) {
        
       
        int peak = getPeak(nums);
        
        // return nums[peak];
        return peak;
        
    }
};