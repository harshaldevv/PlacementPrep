class Solution {
public:
    int change(int amount, vector<int>& coins) {
        
        int  n = coins.size();
        int  W = amount;
        
        int t[n+1][W+1];
        //mapping it to Knapsack (unbounded) but with different intialization
       
        memset(t, -1, sizeof(t));
        
        // fill first row with 0;
        for(int  j = 0 ; j < W +1 ; j++){
            t[0][j] = 0;
        }
        
        // fill first col with 1
        for(int i = 0 ; i < n+1 ; i++){
            t[i][0] = 1;
        }
        
        for(int i =1 ; i < n+1 ; i++){
            for(int j = 1 ; j < W+1; j++){
                if(coins[i-1] <= j){
                    t[i][j] = t[i-1][j] + t[i][j-coins[i-1]];
                }
                else{
                    t[i][j] = t[i-1][j];
                }
            }
        }
        
        return t[n][W];
    }
};