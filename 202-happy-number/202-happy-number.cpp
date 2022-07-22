class Solution {
public:
    bool isHappy(int n) {
        unordered_set<int> s;
        
        while(n != 1){
            if(s.find(n) == s.end()){
                // not found in our set
                // therefore insert in the set
                s.insert(n);
            }
            else{
                // found in our set
                // aka cycle detected
                return false;
            }
            
            int sum = 0;
            while(n){
                int temp = n%10;
                sum += (temp*temp);
                n/= 10;
            }
            
            n = sum;
        }
        
        
        return true;
    }
};