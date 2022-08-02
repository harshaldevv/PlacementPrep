class Solution {
public:
    bool isPowerOfTwo(int n) {
        long long nn = (long long)n;
        if(nn==0){
            return false;
        }
        if( nn & nn-1){
            return false;
        }
        else{
            return true;
        }
        
    }
};