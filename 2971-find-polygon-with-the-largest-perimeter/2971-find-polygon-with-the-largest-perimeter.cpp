class Solution {
public:
    long long largestPerimeter(vector<int>& nums) {
        
        sort(nums.begin(), nums.end());
        
        long long peri = 0;
        
        for(int i = 0 ; i < nums.size(); i++){
            peri += nums[i];
        }
        
        long long i = nums.size() -1;
        
        while(i>=2){
            if(peri > 2*nums[i]){
                return peri;
            }
            else{
                peri -=nums[i];
                i--;
            }
        }
        
        return -1;
        
    }
};