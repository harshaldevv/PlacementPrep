class Solution {
public:
    bool doBS(vector<int> &nums, int l, int r, int &k){
        while(l<=r){
            int mid = l + (r-l)/2;
            
            if(nums[mid] == k){
                return true;
            }
            else if(nums[mid] > k){
                r--;
            }
            else{
                l++;
            }
        }
        
        return false;
    }
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        int n = matrix[0].size();
        
        int l = 0;
        int r = m-1;
        
        while(l<=r){
            int mid = l + (r-l)/2;
            
            if(matrix[mid][0] <= target && target <= matrix[mid][n-1]){
                return doBS(matrix[mid], 0, n-1, target);
            }
            else if(matrix[mid][0] > target){
                r--;
            }
            else{
                l++;
            }
        }
        
        return false;
        
    }
};