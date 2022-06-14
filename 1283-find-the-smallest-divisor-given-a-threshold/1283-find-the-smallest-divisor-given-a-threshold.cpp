class Solution {
public:
    int isvalid(int divisor, vector<int> &nums, int threshold){
        int sum = 0;
        for(auto x : nums){
            int t= x/divisor;
            if(x%divisor != 0){
                t++;
            }
            sum+=t;
            if(sum > threshold){
                return false;
            }
        }
        
        return true;
    }
    int smallestDivisor(vector<int>& nums, int threshold) {
        int start  = 1;
        int end = 1000000;
        int res = -1;
        while(start <= end){
            int mid = start + (end-start)/2;
            
            if(isvalid(mid, nums, threshold)){
                res = mid;
                end = mid -1;
            }
            else{
                start = mid +1;
            }
        }
        
        return res;
    }
};