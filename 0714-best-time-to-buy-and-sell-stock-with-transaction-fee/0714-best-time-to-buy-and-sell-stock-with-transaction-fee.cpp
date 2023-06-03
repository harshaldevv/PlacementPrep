class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        
        int n = prices.size();
        
        
        // tabulation with space optimization
        vector<int> after(2, 0);        
        vector<int> curr (2, 0);
        
        for(int i = n-1 ; i >=0 ; i--){
            for(int j = 0 ; j <= 1 ; j++){
                
                if(j){
                    //two options -> buy or not buy
                    int notBuy = after[true];
                    int iBuy = -prices[i] -fee + after[false];
                    curr[j] = max(notBuy, iBuy);
                }
                else{
                    //sell or not sell
                    int notsell = after[false];
                    int sell = prices[i] + after[true];
                    curr[j] = max(sell, notsell);
                }  
            }
            
            after = curr;
        }
        
        return curr[1];
        
        
        
        
    }
};