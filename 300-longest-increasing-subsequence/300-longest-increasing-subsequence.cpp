class Solution {
    
    int LCS(vector<int> X, vector<int> Y){
        int n = X.size();
        int m = Y.size();
        
        int t[n+1][m+1];
        
        for(int i = 0 ; i < n+1 ; i++){
            t[i][0] = 0;
        }
        
        for(int j = 0 ; j < m+1 ; j++){
            t[0][j] = 0;
        }
        
        for(int i =1 ; i < n+1 ; i++){
            for(int j = 1 ; j < m+1 ; j++){
                if(X[i-1] == Y[j-1]){
                    t[i][j] = 1 + t[i-1][j-1];
                }
                else{
                    t[i][j] = max(t[i-1][j], t[i][j-1]);
                }
            }
        }
        
        return t[n][m];
    }
    
    vector<int> removeDuplicates(vector<int> v, int n){
        vector<int> ans;
        
        for(int i = 0 ; i < n ; i++){
            if(ans.size() == 0){
                ans.push_back(v[i]);
                continue;
            }
            
            if(ans.back() != v[i]){
                ans.push_back(v[i]);
            }
            
        }
        
        return ans;
    }
    
public:
    int lengthOfLIS(vector<int>& nums) {
        
        vector<int> arr1  = nums;
        
        vector<int> arr2 = nums;
        
        sort(arr2.begin(), arr2.end());
        
        // remove duplicates from arr2
        arr2 = removeDuplicates(arr2, arr2.size());
        
        return LCS(arr1, arr2);
        
    }
};