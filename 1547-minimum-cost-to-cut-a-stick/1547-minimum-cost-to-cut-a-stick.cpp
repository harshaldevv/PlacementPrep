class Solution {
public:
    int f(int i, int j, vector<int> &arr, vector<vector<int>> &dp){
        if(i>j){
            return 0;
        }
        if(dp[i][j] != -1){
            return dp[i][j];
        }
        int ans = 1e9;
        
        for(int k = i ; k <= j ; k++){
            int temp = arr[j+1] - arr[i-1] + f(i, k-1, arr, dp) + f(k+1, j, arr, dp);
            ans = min(ans, temp);
        }
        
        return dp[i][j] = ans;
    }
    int minCost(int n, vector<int>& cuts) {
        int sz = cuts.size();
        
        cuts.push_back(n);
        cuts.insert(cuts.begin(), 0);
        
        sort(cuts.begin(), cuts.end());
        
        vector<vector<int>> dp(sz+2, vector<int>(sz+2, -1));
        
        return f(1, sz, cuts, dp);
        
    }
};