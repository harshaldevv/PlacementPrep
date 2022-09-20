class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int ans = 0;
        for(int i = 2 ; i < n ; i++){
            
            int c = nums[i];
            
            int l = 0;
            int r = i-1;
            
            while(l<r){
                int a = nums[l];
                int b = nums[r];
                
                if(a + b > c){
                    ans += (r - l );
                    r--;
                }
                else{
                    l++;
                }
            }
        }
        
        return ans;
    }
};