class Solution {
public:
    bool hasAlternatingBits(int n) {
        
        // find MSB
        int i = 31;
        while(i>=0){
            if( (n & 1<<i) != 0){
                break;
            }
            i--;
        }
        
        int ONE = true;
        for(; i>= 0 ; i--){
            // cout << "i = " << i << endl;
            if(ONE && (n & 1<<i) == 0 ){
                // cout << (n & 1<<i) << endl;
                // cout << "here" ;
                return false;
            }
            else if(!ONE && (n & (1<<i)) != 0 ){
                // cout << (n & 1<<i) << endl;
                // cout << "here2"<< endl;
                return false;
            }
            
            ONE = !ONE;
        }
        
        
        return true;
    }
};