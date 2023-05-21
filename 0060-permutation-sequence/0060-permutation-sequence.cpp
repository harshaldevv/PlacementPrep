class Solution {
public:
    string getPermutation(int n, int k) {
        
        vector<int> number;
        for(int i =1 ; i <= n ; i++){
            number.push_back(i);
        }
        
        vector<int> factorial;
        factorial.push_back(1) ; // 0! = 1
        int f = 1;
        for(int i = 1 ; i <= n ; i++ ){
            f *= i;
            factorial.push_back(f);
        }
        
        
        k-- ; // getting k in zero based indexing
        
        string ans = "";
        
        while(n){
            int f = factorial[n-1];
            
            int jump = k/f;
            
            ans += to_string(number[jump]);
            
            number.erase(number.begin() + jump);
             
            k%= f; // kitne numbers aur bach rahe hai
            n--;
            
        }
        
        return ans;
        
        
    }
};