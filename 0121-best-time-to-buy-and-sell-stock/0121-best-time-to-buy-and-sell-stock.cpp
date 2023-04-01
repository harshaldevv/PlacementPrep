class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxprofit = 0;
        int n = prices.size();
        int minSoFar = INT_MAX;
        
        for(int i = 0 ; i < n ; i++){
            minSoFar = min(prices[i], minSoFar);
            int profitToday = prices[i] - minSoFar;
            maxprofit = max(profitToday, maxprofit);
        }
        
        return maxprofit;
        
    }
};