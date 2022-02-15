class Solution {
    
    int countSubset(vector<int> &nums, int sum){
        int n = nums.size();
        
        int t[n+1][sum+1];
        
        for(int i = 0 ; i < n+1 ; i++){
            t[i][0] = 1; 
        }
        
        for(int j = 0 ; j < sum+1; j++){
            t[0][j] = 0;
        }
        
        t[0][0] = 1;
        
        for(int i = 1 ; i < n+1 ; i++){
            for (int j = 0 ; j < sum +1 ; j++){
                if(nums[i-1] <= j){
                    t[i][j] = t[i-1][j] + t[i-1][j-nums[i-1]];
                }
                else{
                    t[i][j] = t[i-1][j];
                }
            }
        }
        
        return t[n][sum];
        
    }
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        // if(nums == NULL){
        //     return 0;
        // }
        
        int n = nums.size();
        
        if(n == 0){
            return 0;
        }
        
        if(n==1){
            if(nums[0] == abs(target)){
                return 1;
            }
            else{
                cout <<" here " << endl;
                return 0;
            }
        }
        
        int sum_arr = 0;
        int zero_count = 0;
        
        for(int i = 0 ; i < nums.size() ; i++){
            sum_arr+=nums[i];
            if(nums[i] == 0){
                zero_count++;
            }
        }
        
        if(target > sum_arr ){
            cout <<" here 2" << endl;
            return 0;
        }
        
        if( (sum_arr+target)%2 != 0){
            return 0; // odd number hai basically, 
        }
        
        cout <<" here 3" << endl;
        return countSubset(nums,floor(abs(sum_arr - target))/2 ) ;//* (1<<zero_count);
        // count the number of subsets such that difference b/w the subset is target
        
    }
};