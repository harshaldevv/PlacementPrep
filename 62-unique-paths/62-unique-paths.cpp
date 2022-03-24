class Solution {
public:
    //int dp[100+1][100+1];
    int uniquePaths(int m, int n) {
        
        
        // combinatorics way --> TC - O(min(m,n)), SC - O(1)
        
        long N = m+n-2;
        long R = min(m,n)-1;
        
        //do N_C_R
        
        long ans = 1;
        int j = 1;
        for(int i = N; i >= max(m,n); i--){
            ans *= (i);
            ans/=j;
            j++;
        }
        
        return ans;
        
        
        
        
        
        // tabulation space optimized -> TC - O(m+n), SC - O(n) aka number of columns
        
        // feeling lelo is code ki kaise likhna hai, mene thora sloppy way me likha hai isko
        
//         vector<long> t(n+1, 1);
//         for(int i = 1 ; i < m; i++){
//             for(int j = 1 ; j < n+1 ; j++){
//                 t[j] += t[j-1];
//             }
//         }
        
        
//         return t[n-1];
        
        
        
        // tabulation -- TC - O(m+n), SC - O(m+n)
        
        
//         int t[m+1][n+1];
//         memset(t, -1, sizeof(t));
        
//         // filling base case
//         for(int i = 1 ; i < n+1 ; i++){
//             t[1][i] = 1;
//         }
        
//         for(int i = 1 ; i < m+1 ; i++){
//             t[i][1] = 1;
//         }
        
        
//         for(int i = 2 ; i < m+1 ; i++){
//             for(int j = 2 ; j < n+1 ; j++){
//                 t[i][j] = t[i-1][j] + t[i][j-1];
//             }
//         }
        
//         return t[m][n];
        
        
        
        // recursion --> TC - O(2^[m+n]), SC - O(m+n) ->inbuilt recursive stack
        
        // then memoization --> TC - O(m+n), SC - O(m+n)
        // memset(dp, -1, sizeof(dp));
        // return helper(m,n);
    }
    
//     int helper(int m, int n){
//         if(m==1 || n ==1){
//             dp[m][n] = 1;
//             return 1;
//         }
        
//         if(dp[m][n] != -1){
//             return dp[m][n];
//         }
        
//         dp[m][n] =  helper(m,n-1) + helper(m-1, n);
//         return dp[m][n];
        
//     }
};