class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        // In this ques , we are asked "closest 3sum" to target
        // therefore we want abs(target-sum) to be as minimum as possible 
        // range of abs(target-sum) starts from 0 to +INF
        // abs(target-sum) =0 if sum = target
        // else we'll keep searching for our answer
        // we'll keep checking the difference with our minimum diff (aka mini here)
        // if our current difference is less than our current "mini", we'll
        // update the "mini", which stores our minimum difference so far
        // and also store this current "sum" we got (from the 3 elements) in our
        // answer variable
        
        int mini = INT_MAX; // this holds our difference |target-sum|
        int ans; // this holds our ans
        
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
                
                
                if( abs(target-sum)  < mini ){
                    mini = abs(target-sum);
                    ans = sum;
                }
                
                if(sum == target){
                    // agar hume target hi mil gaya toh hum closest ho gaye na
                    // cuz we wanted to minise our abs(target-sum).
                    // here abs(target-sum) = 0, ho gaya
                    // therefore return sum
                    return sum;
                }
                else if(sum < target){
                    l++;
                }
                else{
                    r--;
                }
            }
            
            //rolling the duplicates of number 1
            while(i+1 < n && nums[i] == nums[i+1]){
                i++;
            }
        }
        
        return ans;
        
    }
};