class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ans = 0;
        for(int i = 0; i < 32 ; i++){
            int s = 0;
            for(auto &x : nums){
                if(x >> i & 1){
                    s +=1;
                }
            }
            
            if(s%3){
                ans = ans ^ (1<<i);
            }
            
            s = 0;
        }
        
        return ans;
        
    }
};