class Solution {
public:
    vector<int> countBits(int n) {
        
        //hci research
        vector<int> dp(n+1);
        dp[0] = 0;
        for(int i=1;i<=n;i++){
            dp[i] = dp[i&(i-1)]+1;
        }
        return dp;
        
    }
};