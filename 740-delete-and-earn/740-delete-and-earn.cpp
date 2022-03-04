class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        int n = 10000+1;
        
        vector<int> sum(n, 0);
        
        for(int i = 0 ; i < nums.size() ;i++){
            sum[nums[i]] += nums[i];
        }
        
        vector<int> t(n, -1);
        return rob(sum, n-1, t);
        
    }
    
    int rob(vector<int> &arr, int n, vector<int> &t){
        if( n<0){
            return 0;
        }
        if(n==0){
            return t[n] = arr[n];
        }
        if(t[n] != -1){
            return t[n];
        }
        
        return t[n] = max(arr[n] + rob(arr, n-2, t), rob(arr, n-1, t));
    }
};