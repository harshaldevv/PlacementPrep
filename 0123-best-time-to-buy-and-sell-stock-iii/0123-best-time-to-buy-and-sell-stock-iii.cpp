class Solution {
public:

    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        
        // vector<vector<vector<int>>> dp(n+1, vector<vector<int>>(2, vector<int>(3, 0))); // 
        // j and k wale ko badha kar dia mene for no reason to avoid out of bounds error;

        // n-1 to 0
        // false to true
        // 0 to 3

        vector<vector<int>> curr(2, vector<int>(4, 0));
        vector<vector<int>> next(2, vector<int>(4, 0));

        for(int i = n-1 ;i >=0; i--){
            for(int j = 0 ; j<= 1; j++){
                for(int k = 0 ; k <= 3 ; k++){
                    
                    bool canBuy = j;

                    if(k == 0){
                        curr[j][k] = 0;
                    }
                    else{
                        if(canBuy){
                            // true hai , can buy
                            int buy =  -prices[i] + next[false][k-1]; // buy
                            int skip  = next[true][k]; // skip
                            curr[canBuy][k] = max(buy, skip);
                        }
                        else{
                            // cannot buy
                            // hold or sell
                            int hold = next[false][k]; // hold
                            int sell = +prices[i] + next[true][k]; // sell

                            curr[canBuy][k] = max(hold, sell);
                        }
                    }
                }
                next = curr;
            }
        }

        return curr[true][3];

        
    }
};