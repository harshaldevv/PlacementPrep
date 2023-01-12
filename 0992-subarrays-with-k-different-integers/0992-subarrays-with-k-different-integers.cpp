class Solution {
public:
    int helper(vector<int> &nums, int k){
        unordered_map<int, int> mp;
        
        int l = 0;
        int r = 0;
        int n = nums.size();
        int ans = 0;
        
        while(r < n){

            mp[nums[r]]++;
            
            while(mp.size() > k ){
                int temp = nums[l];
                mp[temp]--;
                l++;
                if(mp[temp] == 0){
                    mp.erase(temp);
                }

            }
            
            ans += (r-l +1);
            
            r++;
        }
        
        return ans;

    }
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        
                return helper(nums, k) - helper(nums, k-1);
    }
};