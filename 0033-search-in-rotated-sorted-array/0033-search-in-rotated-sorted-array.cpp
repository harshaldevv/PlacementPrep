class Solution {
public:
    int getPivot(vector<int> &nums){
        int n = nums.size();
        int l = 0;
        int r = nums.size() -1;
        
        while(l<=r){
            int mid = l + (r-l)/2;
            
            if(nums[l] <= nums[r]){
                return l;
            }
            
            int leftIndex = (mid-1+n)%n;
            int rightIndex = (mid+1)%n;
            
            if(nums[mid] <= nums[leftIndex] && nums[mid] <= nums[rightIndex]){
                return mid;
            }
            else if(nums[l] <= nums[mid]){
                // left half sorted, go in right half (unsorted)
                l = mid +1;
            }
            else{
                // right half sorted, go in left half (unsorted)
                r = mid -1;
            }
        }
        
        return 0;
    }
    
    int BS(int l, int r, vector<int> &nums, int &target){
        // cout << "here" << endl;
        
        while(l<=r){
            int mid = l + (r-l)/2;
            if(nums[mid] == target){
                return mid;
            }
            else if(nums[mid] > target){
                // go left
                r = mid-1;
            }
            else{
                l = mid +1;
            }
        }
        
        return -1;
    }
    int search(vector<int>& nums, int target) {
        
        int pivot = getPivot(nums);
        // cout << "Pivot = " << pivot << endl;
        
        int ans = BS(0, pivot-1, nums, target);
        if(ans == -1){
            return BS(pivot, nums.size()-1, nums, target);
        }
        else{
            return ans;
        }
        
    }
};