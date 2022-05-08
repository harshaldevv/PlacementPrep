class Solution {
public:
    int findMin(vector<int>& nums) {
        
        int start = 0;
        int end = nums.size() -1;
        int n = nums.size();
        
        
        
        while(start <= end){
            
            if(nums[start] <= nums[end]){
            return nums[start]; // array already sorted;
            }
            
            int mid = start + (end- start)/2;
            
            int next = (mid +1)%n;
            int prev = (mid-1+n)%n;
            
            if(nums[mid] < nums[prev] && nums[mid] < nums[next]){
                return nums[mid];
            }
            else if(nums[start] <= nums[mid]){
                //sorted array hai ye,
                // find in the other half
                start = mid+1;
            }
            else{
                end = mid -1;
            }
        }
        
        
        return -5001;
        
    }
};