class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        
        int n = nums.size();
        k = k%n;
        reverse(nums, 0, n-1);
        reverse(nums, 0, k-1);
        reverse(nums, k, n-1);
        
        
    }
    
    void reverse(vector<int> &nums, int i, int j){
        // this functions rverse the list from idnex i to j
        
        int l = i;
        int r = j;
        
        while ( l <r){
            swap(nums[l], nums[r]);
            l++;
            r--;
        }
        
        
    }
};