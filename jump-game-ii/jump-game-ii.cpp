class Solution {
public:
    int jump(vector<int>& nums) {
        
        int n = nums.size();
        if( n < 2){
            return 0;
        }
        
        int jumps = 0;
        int curEnd = 0;
        int curFarthest = 0;
        
        for(int i = 0 ;  i < n-1 ; i++){
            
            curFarthest = max(curFarthest, i +nums[i]);
            
            
            if(i == curEnd){
                jumps++;
                curEnd = curFarthest;
            }
            
        }
        
        return jumps;
    }
};