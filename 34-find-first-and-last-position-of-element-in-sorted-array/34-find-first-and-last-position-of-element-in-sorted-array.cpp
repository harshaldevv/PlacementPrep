class Solution {
public:
    int first(vector<int> &arr, int target){
        int n = arr.size();
        int start = 0;
        int end = n-1;
        int res = -1;
        while(start<= end){
            int mid = start + (end-start)/2;
            if(arr[mid] == target){
                // go left
                res = mid;
                end = mid-1;
            }
            else if(arr[mid]>target){
                //goleft
                end = mid-1;
            }
            else{
                start = mid+1;
            }
        }
        
        return res;
    }
    
    int last(vector<int> &arr, int target){
        int n = arr.size();
        int start = 0;
        int end = n-1;
        int res = -1;
        while(start<= end){
            int mid = start + (end-start)/2;
            if(arr[mid] == target){
                // go right
                res = mid;
                start = mid+1;
            }
            else if(arr[mid] > target){
                //go left
                end = mid -1;
            }
            else{
                start = mid+1;
            }
        }
        return res;
       
    }
    vector<int> searchRange(vector<int>& nums, int target) {
        
        
        vector<int> ans(2, -1);
        if(nums.size() == 1 ){
            if(nums[0] == target){
                ans[0] = 0;
                ans[1] = 0;
                return ans;
            }
            else{
                return ans;
            }
        }
        ans[0] = first(nums, target);
        ans[1] = last(nums, target);
        
        return ans;
        
    }
};