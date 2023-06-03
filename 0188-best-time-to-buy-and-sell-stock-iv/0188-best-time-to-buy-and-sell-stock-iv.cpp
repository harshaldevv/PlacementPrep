class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        
        // tabulation with space optimisation
        
        vector<int> ahead (2*k + 5, 0);
        vector<int> curr (2*k + 5, 0);
        
        for(int i = n -1 ; i >= 0 ; i--){
            for(int j = 2*k ; j>=0 ; j--){
                
                if(j%2 == 0){
                    //buy
                    // buy, not buy
                    int buy = -prices[i] + ahead[j+1];
                    int notbuy = ahead[j];
                    curr[j] =  max(buy, notbuy);
                }
                else{
                    //sell
                    // sell, not sell
                    int sell = +prices[i] + ahead[j+1];
                    int notsell = ahead[j];

                    curr[j] =  max(sell, notsell);
                }
            }
            
            ahead = curr;
        }
        
        return ahead[0];
        
    }
};