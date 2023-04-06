class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int cnt = 0;
        int e = 0;
        
        for(auto &x : nums){
            if(cnt == 0){
                e = x;
            }
            
            if(x ==e){
                cnt++;
            }
            else{
                cnt--;
            }
        }
        
        return e;
        
    }
};