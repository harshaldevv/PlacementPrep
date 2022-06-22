class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int n = nums.size();
        
        vector<int> left(n);
        vector<int> right(n);
        
        int l = 0;
        int r = 0;
        for(int i = 0 ; i < n ; i++){
            l+=nums[i];
            r+=nums[n-1-i];
            left[i] = l;
            right[n-1-i] = r;
        
        }
        
        for(int i = 0 ; i < n ; i++){
            if(left[i] == right[i]){
                return i;
            }
        }
        
        return -1;
    }
};