class Solution {
public:
    
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        
        // https://www.interviewbit.com/problems/subarrays-with-distinct-integers/
        
        
        // trick --> Exact(k) = atMost(k) - atMost(k-1);
        
        return subaaraysWithAtMost_K_Distinct(k, nums)- subaaraysWithAtMost_K_Distinct(k-1, nums);
        
    }
    
    int subaaraysWithAtMost_K_Distinct(int k , vector<int> &nums){
        
        int l = 0;
        int r = 0;
        int n = nums.size();
        
        int cnt = 0;
        
        unordered_map<int, int> mp;
        
        while(r<n){
            
            mp[nums[r]]++;
            
            while(mp.size() > k){
                mp[nums[l]]--;
                if(mp[nums[l]] == 0){
                    mp.erase(nums[l]);
                }
                l++;
            }
            
            cnt += (r-l +1);
            r++;
        }
        
        return cnt;
    }
};