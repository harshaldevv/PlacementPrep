class Solution {
public:
    
    int doBinarySearch(vector<int> &nums, int target, int l, int r){
        // find all X st X < target 
        int start = l;
        int ans = 0;
        
        while(l <= r){
            
            int mid = l + (r-l)/2;
            
            if( nums[mid] >= target){
                
                r = mid -1;
            }
            else if(nums[mid]  < target){
                // ans = mid;
                l = mid +1;
            }
        }
        
        return l - start ;
    }
    int triangleNumber(vector<int>& nums) {
        
        sort(nums.begin(), nums.end());
        
        int n = nums.size();
        
        int ans = 0;
        
        for(int i = 0 ; i <  n ; i++){
            for(int j = i +1 ; j < n ; j++){
                
                int a = nums[i];
                int b = nums[j];
                
                // c < a + B find
                // find all c such that c < sum
                
                ans += doBinarySearch(nums, a+b, j+1, nums.size() -1);
            }
        }
        
        return ans;
        
    }
};