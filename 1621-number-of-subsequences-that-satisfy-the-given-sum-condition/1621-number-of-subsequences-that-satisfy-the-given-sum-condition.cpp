class Solution {
public:
    int numSubseq(vector<int>& nums, int target) {

        sort(nums.begin(), nums.end());
        int n = nums.size();
        int l = 0;
        int r = n-1;
        long long ans = 0;
        int mod = 1e9 + 7; 
        // pre compute the powers
        vector<long long> powers(n+1, -1);
        powers[0] = 1;
        for(int i = 1 ; i < n ; i++ ){
            powers[i] = (powers[i-1]*2)%mod;
        }
        while(l<=r && r >=0 ){
            long long sum = nums[l] + nums[r];
            if(sum <= target){
                ans+= ((powers[r-l])%mod);
                ans %= mod;
                l++;
            }
            else{
                r--;
            }
        }

        return ans;
        
    }
};