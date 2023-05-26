class Solution {
public:
    
    int f(int i, int j, vector<vector<int>> &t, int &n, vector<vector<int>> &dp){
        cout << "i,j " << i << " , " << j << endl;
        if(i == n-1){
            return t[i][j];
        }
        
        if(dp[i][j] != -1){
            return dp[i][j];
        }
        
        int down = f(i+1, j, t, n, dp);
        int dia = f(i+1, j+1, t, n, dp);
        
        return dp[i][j] = (min(down, dia) + t[i][j]);
        
    }
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        
        // vector<vector<int>> dp(n+1, vector<int>(n+1, -1));
        // return f(0,0, triangle, n, dp);
        
        
        //tabulation done
        // we go from n-1 to 0 (in tabulation) as we went from 0 to n-1 in memoization.
        vector<vector<int>> dp(n+1, vector<int>(n+1, -1));
        for(int i = n-1 ; i >=0 ; i--){
            for(int j = i ; j >= 0 ; j--){
                if(i == n-1){
                    dp[i][j] = triangle[i][j];
                }
                else{
                    int down = dp[i+1][j];
                    int dia = dp[i+1][j+1];

                    dp[i][j] = min(down, dia) + triangle[i][j];
                    
                }
            }
        }
        
        return dp[0][0];
        
        
        
    }
};