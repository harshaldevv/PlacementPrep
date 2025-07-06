class Solution {
public:
    int f(int i, int j, vector<int> &nums){
        if(i<0){
            return 0;
        }

        if(j<0){
            return 0;
        }


        if(i==0){
            if(j== 0){
                return 1;
            }
            else if(j%nums[i] == 0 ){
                return 1;
            }
            else{
                return 0;
            }
        };


        int pick = f(i, j - nums[i], nums);
        int notpick = f(i-1, j, nums);

        return pick + notpick;
    }

    int change(int amount, vector<int>& coins) {

        int n = coins.size();
        vector<vector<unsigned int>> dp(n+1, vector<unsigned int>(amount +1, 0));

        for(int i = 0 ; i < n ; i++){
            dp[i][0] = 1;
        }

        for(int i = 0 ; i < n ; i++){
            for(int j = 1 ; j <= amount ; j++){

                if(i==0){
                    if(j%coins[i] == 0 ){
                        dp[i][j] = 1;
                    }
                    else{
                        dp[i][j] = 0;
                    }
                }
                else{
                    long long pick = 0;
                    long long notpick = 0;

                    if( j - coins[i] >= 0){
                        pick = dp[i][j - coins[i]];
                    }

                    // cout << pick << ", ";

                    if(i-1 >=0 ){
                        notpick = dp[i-1][j];
                    }

                    // cout << "notpick = "  << notpick << endl;

                    dp[i][j] = pick + notpick;
                }
            }
        }

        return dp[n-1][amount];
    }
};