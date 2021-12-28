class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        
        if(nums.size() == 1){
            return;
        }
        
        if(nums.size() == 2){
            if(nums[0] < nums[1]){
                swap(nums[0], nums[1]);
                return ;
            }
        }
        
        
        int i = nums.size() -1;
        
        for(; i >=1 ; i--){
            if(nums[i] > nums[i-1]){
                i--; // we got the index where our condiitons is satifised
                break;
            }
        }
        
        if( i == 0 && nums[0] > nums[1]){
            sort(nums.begin(), nums.end());
            return;
        }
        
        // now finding the larger number
        int j = nums.size() -1;
        for( ; j >=1 ; j--){
            if(nums[j] > nums[i] ){
                swap(nums[j], nums[i]);
                break;
            }
        }
        
        // now we need to reverse the whole array from i+1 to j
        
        i++;
        
        j = nums.size() -1;
        
        while ( i<=j){
            swap(nums[i], nums[j]);
            i++;
            j--;
        }
        
    }
};