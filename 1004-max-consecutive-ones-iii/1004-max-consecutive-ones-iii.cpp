class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        // the problem is nothing but finding the longest window with atmost k zeros.
        
        int zeroCount = 0;
        int i = 0;
        int j = 0;
        int size = 0;
        for( ; j < nums.size() ; j++){
            if(nums[j] == 0){
                zeroCount++;
            }
            //invalid window.
            //gotta reduce its size till zerocount < k
            while(zeroCount > k){
                //jabtak zerocunt k se bada
                //ghatae jao
                if(nums[i] == 0){
                    zeroCount--;
                }
                i++;
                
            }
            size = max(size, j-i+1);
        }
        
        return size;
    }
};