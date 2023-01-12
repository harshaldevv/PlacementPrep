class Solution {
public:
    
    int BS(int l, int r, int sum, vector<int> &nums){
        int start = l;
        while(l<= r){
            int mid = l + (r-l)/2;
            if(nums[mid] < sum){
                l = mid +1;
            }
            else{
                r = mid -1;
            }
        }
        
        return l - start;
        
        
    }
    int triangleNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int ans = 0;
        for(int i = 0 ; i < n ; i++){
            for(int j = i +1 ; j < n ; j++){
                int a = nums[i];
                int b = nums[j];
                
                ans += BS(j+1, n-1, a+b, nums);
            }
        }
        
        return ans;
        
    }
};