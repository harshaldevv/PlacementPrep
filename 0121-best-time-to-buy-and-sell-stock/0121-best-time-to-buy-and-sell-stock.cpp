class Solution {
public:
   
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int mini = INT_MAX;
        int profit = 0;
        for(auto &x : prices){
            mini = min(mini, x);
            profit = max(profit, abs(x - mini) );
        }
        
        return profit;
        
    }
};