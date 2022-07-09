class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        
        // k sum --> 
        // general algo for k > 2--> 
        // 1) sort the array
        // 2) run "K-2" for loops
        // 3) then use 2 ptr approach to get the desired sum
        // 4) handle duplicates well
        
        
        vector<vector<int>> ans;
        int n = nums.size();
        sort(nums.begin(), nums.end());
        
        int target = 0;
        
        for(int i = 0 ; i < nums.size() ; i++){
            int l = i+1;
            int r = nums.size() -1;
            
            while(l<r){
                int a = nums[i];
                int b = nums[l];
                int c = nums[r];
                
                int sum = a + b + c;
                
                if(sum == target){
                    ans.push_back({a,b,c,});
                    
                    while(l < r && nums[l] == nums[l+1]){
                        l++;
                    }
                    
                    while(l<r && nums[r] == nums[r-1]){
                        r--;
                    }
                    
                    // after you've checked for your duplicates, then
                    // increment the pointers
                    
                    l++;
                    r--;
                }
                else if(sum < target){
                    l++;
                }
                else{
                    r--;
                }
            }
            
            while( i+1 < n && nums[i] == nums[i+1]){
                i++;
            } 
        }
        
        return ans;
            
        
    }
};