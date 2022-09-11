class Solution {
public:
    string getPermutation(int n, int k) {
        
        // TC - O(n) * O(n) = O(n^2)
        // SC - O(n)
        
        vector<int> numb;
        
        for(int i=1 ; i <= n ; i++){
            numb.push_back(i);
        }
        
        vector<int> fact;
        int f = 1;
        fact.push_back(f); // 0! is equal to 1
        
        for(int i =1 ; i <= n ; i++){
            f *= i;
            fact.push_back(f);
        }
        
        k--;
        
        string ans = "";
        
        while(n){
            int factt = fact[n-1];
            int index = k / factt;
            ans += to_string(numb[index]);
            numb.erase(numb.begin() + index);
            
            k %= factt;
            n--;
        }
        
        return ans;
        
    }
};