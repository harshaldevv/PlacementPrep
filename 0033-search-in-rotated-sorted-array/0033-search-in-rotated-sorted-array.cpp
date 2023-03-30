class Solution {
public:
    int search(vector<int>& nums, int target) {
        
        // hci research 
        int left = 0;
        int right = nums.size() - 1;
        
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] == target) {
                return mid;
            }
            if (nums[left] <= nums[mid]) { // left half is sorted
                if (nums[left] <= target && target < nums[mid]) {
                    right = mid - 1; // target is in left half
                } else {
                    left = mid + 1; // target is in right half
                }
            } else { // right half is sorted
                if (nums[mid] < target && target <= nums[right]) {
                    left = mid + 1; // target is in right half
                } else {
                    right = mid - 1; // target is in left half
                }
            }
        }
        
        return -1; // target not found
    }
};
