class Solution {
public:
    int maxArea(vector<int>& nums) {
        int n = nums.size();
        
        int l = 0;
        int r = n-1;
        
        int ans = min(nums[l], nums[r]) * (r-l);
        
       
//         while(l<r){
            
//             int h = min(nums[l], nums[r]);
//             ans = max(ans, (r-l)*h);
            
//             while(nums[l] <= h && l < r){
//                 l++;
//             }
//             while(nums[r] <= h && l < r){
//                 r--;
//             }
            
            
       
//         }
        
        
        // Both the above algos work -->
        
        while(l<r){
            
            int h = min(nums[l], nums[r]);
            ans = max(ans, (r-l)*h);
            
            // jo pointer's value aka nums[l] or nums[r] chota hai  
            // , hum uske acc step lenge.
            // upar wale algo se less complex types hai
            //mtlb jis pointer pe merkeo min (ie H), ab hum
            // uske aage ya piche jayenge
            // agar L wala min tha, toh hum uske aage jayenge in the hope ki hume
            // lamba pole mil jaye
            // agar R wala min hota hai toh hum uske peeche (ie r--) jayenge 
            // in the hope ki hume lamba pole mil jaye
            
            if(nums[l] < nums[r]){
                l++;
            }
            else{
                r--;
            }

            
        }
        
        return ans;
        
        
        
    }
};