class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        //hitesh sir taught me
        // we want left small, right big
        int i = nums.size() -2;// starting from second last element
        while(i>= 0 && nums[i] >= nums[i+1]){
            i--;
        }
        
        if(i==-1){
            // array is reverse sorted,
            // therefore
            reverse(nums.begin(), nums.end());
            return;
        }
        
        // we got the case
        
        // 1,2,4,3,2,1
        //   ^
        
        // find just bigger number than nums[i]
        // go from behind -> cuz we know array is sorted 
        int next = nums.size() -1;
        while(next){
            if(nums[next] > nums[i]){
                break;
            }
            next--;
        }
        
        swap(nums[i], nums[next]);
        
        // 1,3,4,2,2,1
        //     ^
        
        //now reverse from i+1, to end
        reverse(nums.begin() + i+1, nums.end());
        
        return;
        
        
    }
};