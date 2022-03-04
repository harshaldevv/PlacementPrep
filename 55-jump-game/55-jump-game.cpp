class Solution {
    
    bool solve(vector<int> &nums, int startPos){
        if(startPos >= nums.size() -1 ){
            return true;
        }
        
        bool isReachable = false;
        for(int i = startPos ; i < startPos + nums[startPos] ; i++){
            isReachable = isReachable||solve(nums, startPos + i);
        }
        return isReachable;
    }
    
public:
    bool canJump(vector<int>& nums) {
        
        
       //return solve(nums, 0); 
        
        
        int maxSoFar = 0;
        int n = nums.size();
        
        for(int i = 0 ; i < n ;i++){
            if(i > maxSoFar){
                return false;
            }
            maxSoFar = max(maxSoFar, i + nums[i]);
        }
        
        return true;
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
//         int n = nums.size();
        
//         int currPos = 0;
//         int range = nums[0];
//         bool ans = false;
//         for(int i = currPos; i <= currPos + range ;i++){
//             cout << "currIndex = " << currPos << endl ;
//             int maxFromHere = i + nums[i];
            
//             int howFar = INT_MIN;
//             for(int j = i+1 ; j < i + nums[i] ; j++){
//                 howFar = max(howFar, j + nums[j] -1);
                
//                 if(howFar >= maxFromHere){
//                     currPos = max(howFar, maxFromHere);
//                     range = max(range, nums[j]);
                    
//                 }
                
                
//             }
            
//             // currPos = max(howFar, maxFromHere);
            
//             if(currPos == n-1){
//                 return true;
//             }
            
//         }
        
//         cout << "final " << endl;
//         cout << currPos << endl;
//         if(currPos == n-1){
//             return true;
//         }
//         else{
//             return false;
//         }
        
    }
};