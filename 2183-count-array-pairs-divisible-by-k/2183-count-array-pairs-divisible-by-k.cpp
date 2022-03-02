class Solution {
    
    long long helper(vector<int> &nums, int k){
        // striver approach --> https://www.youtube.com/watch?v=khFetYmKf-4
        long long ans = 0;
        
        int  n = nums.size();
        unordered_map<int, int> mp;
        
        
        for(int i = 0; i < n; i++){
            long long gcd1 = __gcd(nums[i], k);
            long long gcd2 = k/gcd1;
            
            if(gcd2 == 1){
                ans += i;
            }
            else{
                for(auto it: mp){
                    if(it.first%gcd2 == 0){
                        ans+= it.second;
                    }
                }  
            }
            
            mp[gcd1]++;
        }
        
        return ans;
    }
    
public:
    long long countPairs(vector<int>& nums, int k) {
        
        return helper(nums, k); // striver approach
        
        
//         // coding decoded approach ---> https://www.youtube.com/watch?v=3pF0cdWfqSE
//         unordered_map<int, int> mp;
        
//         int n = nums.size();
//         long long ans = 0;
        
//         for(int i = 0 ; i < n ; i++){
            
//             long long gcd1 = __gcd(nums[i], k);
            
//             for(auto it : mp){
//                 int gcd2 = it.first;
                
//                 if( (long long)gcd1 *gcd2 %k ==0 ) {
//                     ans += it.second;
//                 }
//             }
            
//             mp[gcd1]++;
            
//         }
        
//         return ans;
        
    }
};