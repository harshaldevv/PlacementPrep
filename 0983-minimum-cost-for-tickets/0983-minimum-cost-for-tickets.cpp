class Solution {
public:
    int helper(int i, vector<int> &days, vector<int> &costs, vector<int> &dp){
        
        if( i >= days.size() ){
            return 0;
        }
        
        if(dp[i] != -1){
            return dp[i];
        }
        
        // int ind1 = lower_bound(days.begin(),days.end(),days[i]+1)-days.begin();
        // int ind2 = lower_bound(days.begin(),days.end(),days[i]+7)-days.begin();
        // int ind3 = lower_bound(days.begin(),days.end(),days[i]+30)-days.begin();
        
        int ind1 = i;
        
        int ind2 = i;
        int ind3 = i;
        
        for(int x = i ; x < days.size() ; x++){
            if(days[x] < days[i] + 7){
                ind2 = x;
            }
        }
        
        for(int x = i ; x < days.size() ; x++){
            if(days[x] < days[i] + 30){
                ind3 = x;
            }
        }
        // cout << "ind1 = " << ind1 << endl;
        // cout << "ind2 = " << ind2 << endl;
        // cout << "ind3 = " << ind3 << endl;
        // cout << endl;
        int oneDay = costs[0] + helper(ind1+1, days, costs, dp);
        int sevenDay = costs[1] + helper(ind2+1, days, costs, dp);
        int thirtyDay = costs[2] + helper(ind3+1, days, costs, dp);
        
        return dp[i] = min(oneDay, min(sevenDay, thirtyDay));
            
        
        
    }
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        
        int n = days.size();
        // cout << "n = " << n << endl;
        vector<int> dp(n+1, -1);
        return helper(0, days, costs, dp);
        
    }
};