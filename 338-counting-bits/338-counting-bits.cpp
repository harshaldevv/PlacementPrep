class Solution {
public:
    int countSetBits(int n){
        //we could have used the inbuilt function to count the set bits
        // ie --> return __builtin_popcount(n);
        
        // but i wish to write it without using the builtin function
        // therefore --> using the Brian Kernighan’s algo 
        
        int ans = 0;
        while(n){
            ans++;
            n = n& (n-1);
        }
        
        return ans;
        
        // TC --> O(logn) -> tc of this Brian Kernighan’s algo 
        // SC - O(1)
        
    }
    vector<int> countBits(int n) {
        
        // TC - O(N), SC - O(1)
        vector<int> ans(n+1, 0);
        
        ans[0] = 0;
        
        for(int i = 1 ; i <= n ; i++){
            // ans[i] = ans[i/2] + i%2;   // i%2  = 0 for even and 1 for odd
            ans[i] = ans[i/2] + (i&1); // (i&1) --> = 0 for even and 1 for odd;
        }
        return ans;
        
//         // TC = O(nlogn ), SC = O(1) --> is easy, as per follow up
//         vector<int> ans(n+1, -1);
        
//         for(int i = 0 ; i <= n ;i++){
//             ans[i] = countSetBits(i);
//         }
        
//         // we run a for loop --> O(n) for the for loop
//         // and we take O(logn) for the countSetBit() function
//         // therefore TC = O(nlogn) , SC - O(1) --> no extra space used
        
//         return ans;
        
        
    }
};