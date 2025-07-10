class Solution {
public:

    int f(int i, int j, string &s1, string &s2, vector<vector<int>> &dp){

        if( j == 0 ){
            // small string finish -> so we got our subsequence
            return 1;
        }

        if( i == 0){
            // big string finish -> so we didnt find anything 
            return 0;
        }

        if(dp[i][j] != -1){
            return dp[i][j];
        }
        if(s1[i-1] == s2[j-1]){
            return dp[i][j] = f(i-1, j-1, s1, s2, dp) + f(i-1, j, s1, s2, dp);
        }
        else{
            return dp[i][j] = f(i -1, j, s1, s2, dp);
        }
    }
    int numDistinct(string s1, string s2) {

        int n = s1.size();
        int m = s2.size();

        // vector<vector<int>> dp(n +1, vector<int>(m+1, -1));
        // return f(n , m , s1, s2, dp);


        // //iterative
        // vector<vector< unsigned int >> dp(n +1, vector< unsigned int >(m+1, 0));
        // // 0 to n
        // // 0 to m
        
        // for(int i = 0 ; i <= n ; i++ ){
        //     for(int j = 0 ; j <= m ; j++){

        //         if( j == 0 ){
        //             // small string finish -> so we got our subsequence
        //             dp[i][j] = 1;
        //         }
        //         else if( i == 0){
        //             // big string finish -> so we didnt find anything 
        //             dp[i][j] = 0;
        //         }
        //         else if(s1[i-1] == s2[j-1]){
        //             dp[i][j] = dp[i-1][j-1] + dp[i-1][j];
        //         }
        //         else{
        //             dp[i][j] = dp[i -1][j];
        //         }
        //     }
        // }

        // return dp[n][m];

        //iterative - space optimised
        vector<vector< unsigned int >> dp(n +1, vector< unsigned int >(m+1, 0));
        // 0 to n
        // 0 to m

        vector<unsigned int> curr (m+1, 0);
        vector<unsigned int> prev (m+1, 0);
        
        for(int i = 0 ; i <= n ; i++ ){
            for(int j = 0 ; j <= m ; j++){

                if( j == 0 ){
                    // small string finish -> so we got our subsequence
                    curr[j] = 1;
                }
                else if( i == 0){
                    // big string finish -> so we didnt find anything 
                    curr[j] = 0;
                }
                else if(s1[i-1] == s2[j-1]){
                    curr[j] = prev[j-1] + prev[j];
                }
                else{
                    curr[j] = prev[j];
                }
            }

            prev = curr;
        }

        return prev[m];

        
    }
};