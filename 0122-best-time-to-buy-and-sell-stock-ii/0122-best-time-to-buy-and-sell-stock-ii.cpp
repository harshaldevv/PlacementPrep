class Solution {
public:
    int f(int i, vector<int> &prices, bool youcanBuy){
        
        if(i>=prices.size()){
            return 0;
            //end of the days
        }
        
        if(youcanBuy){
            //two options -> buy or not buy
            int notBuy = f(i+1, prices, true);
            int iBuy = -prices[i] + f(i+1, prices, false);
            return max(notBuy, iBuy);
        }
        else{
            //sell or not sell
            int notsell = f(i+1, prices, false);
            int sell = prices[i] + f(i+1, prices, true);
            
            return max(sell, notsell);
        }
        
        
        
        
    }
    int maxProfit(vector<int>& prices) {
        //maybe knapsack pattern
        int n = prices.size();
//         bool youcanBuy = true;
        
//         vector<vector<int>> dp(n+1, vector<int>(2, -1));
        
//         return f(0, prices, youcanBuy, dp);
        
        
        /*
        There is a classical saying in the stock market - "Buy the Dip".
        Same concept you need to apply here
        Compare two consecutive days and if you are making a profit, 
        just buy on 1st day and sell on 2nd day
        */
        int ans = 0;
        for(int i = 1 ; i < n ;i++){
            if(prices[i] >= prices[i-1]){
                ans += prices[i] - prices[i-1];
            }
        }
        
        return ans;
        
    }
};