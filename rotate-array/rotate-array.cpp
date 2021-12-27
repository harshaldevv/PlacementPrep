class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        
        int n = nums.size();
        
        if(k==n) return;
        if(k==0) return;
        if(n<=1) return;
        // if(k == k%n) return; // it means ki effectively k = 0 hai 
        
        k = k%n;  // to bring the k in its limit
        reverse(nums, 0, n-1); // reverse the whole list
        reverse(nums, 0, k-1); // reverse the first k elements
        reverse(nums, k, n-1); // reverse the last n-k elements
        
        
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