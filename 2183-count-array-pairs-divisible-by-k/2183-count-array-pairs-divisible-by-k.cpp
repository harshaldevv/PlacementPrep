class Solution {
public:
    long long countPairs(vector<int>& nums, int k) {
        
        unordered_map<int, int> mp;
        
        int n = nums.size();
        long long ans = 0;
        
        for(int i = 0 ; i < n ; i++){
            
            long long gcd1 = __gcd(nums[i], k);
            
            for(auto it : mp){
                int gcd2 = it.first;
                
                if( (long long)gcd1 *gcd2 %k ==0 ) {
                    ans += it.second;
                }
            }
            
            mp[gcd1]++;
            
        }
        
        return ans;
        
    }
};