class Solution {
public:
    int BS(vector<int> &nums, int target, int l, int r){
        int start = l+1;
        int end = r;
        
        while(start <= end){
            int mid = start + (end-start)/2;
            
            if(nums[mid] == target){
                return mid;
            }
            else if(nums[mid] > target){
                // go left
                end = mid -1;
            }
            else{
                start = mid +1;
            }
        }
        
        return -1;
        
    }
    vector<int> twoSum(vector<int>& numbers, int target) {
        
        for(int i = 0 ; i < numbers.size() ; i++){
            int x = target - numbers[i];
            
            int BS_index = BS(numbers, x, i, numbers.size()-1);
            if(BS_index != -1 ){
                return {i+1, BS_index+1};
            }
        }
        vector<int> v;
        return v;
        
        
    }
};