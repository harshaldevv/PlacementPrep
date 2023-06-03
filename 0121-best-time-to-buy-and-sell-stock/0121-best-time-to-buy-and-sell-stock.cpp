class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        
        int maxProf = 0;
        int minPrice = INT_MAX;
        for(int i = 0 ; i < n;i++){
            minPrice = min(prices[i], minPrice);
            int profToday = prices[i] - minPrice;
            maxProf = max(maxProf, profToday);
        }
        
        return maxProf;
        
    }
};