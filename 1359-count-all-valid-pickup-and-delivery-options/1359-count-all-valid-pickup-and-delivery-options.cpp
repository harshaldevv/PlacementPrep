class Solution {
public:
    int countOrders(int n) {
        
        long long ans = 1;
        int mod = 1000000000 + 7;
        
        for(int i = 2 ; i < n+1 ; i++){
            
            int maxi = 2*i -1;
            
            int totalCombos_for_this_i = ((maxi)*(maxi + 1)/2)%mod;
            cout << "combo for this n = " << totalCombos_for_this_i << endl;
            
            // int temp = (i*(2*i-1))%mod;
            
            ans= (ans * totalCombos_for_this_i)%mod;
            
            // ans = ans*temp;
            
        }
        
        return ans%mod;
        
    }
};