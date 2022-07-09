class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        
        int mini = INT_MAX;
        int ans;
        
        int n = nums.size();
        sort(nums.begin(), nums.end());
        
        for(int i = 0 ; i < nums.size() ; i++){
            
            int l = i+1;
            int r = n-1;
            
            while( l < r){
                int a = nums[i];
                int b = nums[l];
                int c = nums[r];
                
                int sum = a+b+c;
                
                // mini = min(mini, abs(target-sum));
                if( abs(target-sum)  < mini ){
                    mini = abs(target-sum);
                    ans = sum;
                }
                
                if(sum == target){
                    // 
                    return sum;
                }
                else if(sum < target){
                    l++;
                }
                else{
                    r--;
                }
            }
            
            while(i+1 < n && nums[i] == nums[i+1]){
                i++;
            }
        }
        
        return ans;
        
    }
};