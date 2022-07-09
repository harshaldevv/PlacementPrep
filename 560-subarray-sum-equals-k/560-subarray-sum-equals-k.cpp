class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        
        int n = nums.size();
        unordered_map<int, int> mp;
        int psum = 0;
        int ans = 0;
        
        for(int i = 0 ; i < n ; i++){
            psum += nums[i];
            
           if(psum == k){
               ans++;
           }
            
            if(mp.find(psum - k) != mp.end()){
                ans +=  mp[psum - k];
            }
            // else{  // else leke nahi chalega
            //     // mp[psum] = i;
            //     mp[psum]++;
            // }
            mp[psum]++;
        }
        
        return ans;
        
    }
};