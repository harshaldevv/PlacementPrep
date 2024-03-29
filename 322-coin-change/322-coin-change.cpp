class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        
        int n = coins.size();
        
        int t[n+1][amount +1];
        
        
        //first col
        for(int i = 0 ; i < n+1 ; i++){
            t[i][0] = 0;
        }
        
        for(int j = 0 ; j < amount +1 ; j++){
            t[0][j] = INT_MAX -1;
        }
        
        t[0][0] = 0;
        
        
        for(int i =1 ; i < n+1 ; i++){
            for(int j =1 ; j < amount +1 ; j++){
                if(coins[i-1] <= j){
                    t[i][j] = min(t[i-1][j],  1+ t[i][j-coins[i-1]]);
                }
                else{
                    t[i][j] = t[i-1][j];
                }
            }
        }
        
        
        int ans = t[n][amount];
        
        if(ans > amount){
            return -1;
        }
        else{
            return ans;
        }
        
    }
};