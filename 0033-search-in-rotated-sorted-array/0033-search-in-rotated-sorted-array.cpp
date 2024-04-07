class Solution {
public:
    int getPivot(vector<int> &nums){
        int l = 0;
        int r = nums.size() -1;
        int n = nums.size();
        while(l<=r){
            int mid = l + (r-l)/2;
            
            int leftIndex = (mid -1 + n )%n;
            int rightIndex = (mid +1)%n;
            
            if(nums[mid] < nums[leftIndex] && nums[mid] < nums[rightIndex]){
                return mid;
            }
            else if(nums[mid] < nums[r]){
                // right half sorted, go in left half
                r = mid -1;
            }
            else{
                // left half sorted, go in right half
                l = mid +1;
            }
        }
        
        return 0;
    }
    
    int BS(int l, int r, vector<int> &nums, int tar){
        while(l<=r){
            int mid = l + (r-l)/2;
            if(nums[mid] == tar){
                return mid;
            }
            else if(nums[mid] < tar){
                l = mid +1;
            }
            else{
                r = mid -1;
            }
        }
        return -1;
    }
    int search(vector<int>& nums, int target) {
        
        int pivotIndex = getPivot(nums);
        cout << "pivotindex = " << pivotIndex << endl;
        int ans = BS(0, pivotIndex-1, nums, target);
        
        if(ans == -1){
            return BS(pivotIndex, nums.size() -1, nums, target);
        }
        else{
            return ans;
        }
        
    }
};