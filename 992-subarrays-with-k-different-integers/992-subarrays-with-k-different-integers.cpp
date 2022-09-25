class Solution {
public:
    
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        
        return helper(k, nums) - helper(k-1, nums);
    }
    
    int helper (int k, vector<int> &nums){
        int l = 0;
        int r = 0;
        int n = nums.size();
        int ans = 0;
        
        unordered_map<int, int> mp;
        while(r < n){
            auto x = nums[r];
            mp[x]++;
            while(mp.size() > k){
                auto prev = nums[l];
                mp[prev]--;
                l++;
                if(mp[prev] == 0){
                    mp.erase(prev);
                }
            }
            
            // cout << "r , l = " << r << " " << l << endl;
            ans += ( r - l +1);
            
            r++;
        }
        return ans;
    }
};