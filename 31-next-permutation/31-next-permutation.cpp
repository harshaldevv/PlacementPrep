class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        
        // left small , right big
        
        int n = nums.size();
        
        int i = n-2;
        for( ; i >= 0 ; i--){
            if(nums[i] < nums[i+1] ){
                break;
            }
        }
        
        if(i ==-1){
            // array is reverse sorted
            reverse(nums.begin(), nums.end());
            return ;
        }
        
        // next bigger number than nums[left];
        
        int next = n-1;
        
        while(next > i){
            if(nums[next] > nums[i]){
                break;
            }
            next--;
        }
        
        swap(nums[i], nums[next]);
        
        reverse(nums.begin() + i+1 , nums.end());
        
        return ;
        
        
        
    }
};