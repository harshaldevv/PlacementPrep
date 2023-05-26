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
        
        
//         //tabulation done
//         // we go from n-1 to 0 (in tabulation) as we went from 0 to n-1 in memoization.
//         vector<vector<int>> dp(n+1, vector<int>(n+1, -1));
//         for(int i = n-1 ; i >=0 ; i--){
//             for(int j = i ; j >= 0 ; j--){
//                 if(i == n-1){
//                     dp[i][j] = triangle[i][j];
//                 }
//                 else{
//                     int down = dp[i+1][j];
//                     int dia = dp[i+1][j+1];

//                     dp[i][j] = min(down, dia) + triangle[i][j];
                    
//                 }
//             }
//         }
        
//         return dp[0][0];
        
        
        //tabulation with space optimisation 
        // we go from n-1 to 0 (in tabulation) as we went from 0 to n-1 in memoization.
        // vector<vector<int>> dp(n+1, vector<int>(n+1, -1));
        
        vector<int> next(n, 0);
        vector<int> curr(n, 0);
        
        for(int i = 0 ; i < n ; i++){
            next[i] = triangle[n-1][i];
        }
        
        for(int i = n-2 ; i >=0 ; i--){
            for(int j = i ; j >= 0 ; j--){
                    int down = next[j];
                    int dia = next[j+1];

                    curr[j] = min(down, dia) + triangle[i][j];
            }   
            next = curr;
        }
        
        return next[0];
        
    }
};