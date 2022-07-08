class Solution {
    int DnC(vector<int> &nums, int l, int r){
        if(l>r){  return 0; }
        
        if(l ==r){ return nums[l];}
        
        int m = l + (r-l)/2;
        int leftSum = DnC(nums, l, m);     // T(n/2)
        int rightSum = DnC(nums, m+1, r);  // T(n/2)
        
        int midSum = getMiddleSum(nums, l, m , r);
        
        // return max(max(leftSum, rightSum), midSum);
        if(leftSum > rightSum && leftSum > midSum){
            return leftSum;
        }
        else if(rightSum > leftSum && rightSum > midSum){
            return rightSum;
        }
        else{
            return midSum;
        }
        
    }
    int getMiddleSum(vector<int> &nums, int l, int m , int r){
        int sum = 0;
        int maxSoFar = INT_MIN+100;
        int lefty = 0;
        for(int i = m-1; i >= l ; i--){
            sum+= nums[i];
            maxSoFar = max(sum, maxSoFar);
            //sum = max(sum, 0);  --> why why why --> why not having this leads to correct ans
        }
        lefty = maxSoFar;
        
        int righty = 0;
        sum = 0;
        maxSoFar = INT_MIN+100;  // why isnt my INT_MIN working
        for(int i = m+1; i<=r ;i++){
            sum+= nums[i];
            maxSoFar = max(maxSoFar, sum);
            //sum = max(sum, 0);   
        }
        righty = maxSoFar;
        
        cout << lefty << " " << nums[m] << " " << righty << endl;
        
        return lefty + nums[m] + righty;
    }
    
public:
    int maxSubArray(vector<int>& nums) {
        
        //return DnC(nums, 0, nums.size()-1);
        
        
//         // kadane algo 
//         int sum = 0;
//         int maxi = INT_MIN;
        
//         for(int i = 0. ; i < nums.size() ; i++){
            
//             int x = nums[i];
//             sum += x;
            
//             maxi = max(maxi, sum);
            
//             sum = max(sum,0);
//             // if(sum <0){
//             //     sum = 0;
//             // }
            
//         }
        
//         return maxi;
        
        // 8 july 2022
        
        int sum = 0;
        int maxi = nums[0];
        
        for(int i = 0 ; i < nums.size() ; i++){
            sum += nums[i];
            
            maxi = max(maxi, sum);
            
            if(sum < 0 ){
                sum = 0;
            }
        }
        
        return maxi;
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
    }
};