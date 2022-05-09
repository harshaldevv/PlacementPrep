class Solution {
public:
    int mySqrt(int x) {
        long start = 0;
        long end = x;
        int res = -1; //stores the possible answer
        
        while(start <= end){
            long mid = start + (end-start)/2;
            
            if(mid*mid == x){
                return mid;
            }
            else if(mid * mid > x){
                // go left
                //res = mid;
                end = mid -1;
            }
            else{
                res = mid;
                start = mid +1;
            }
        }
        
        return res;
    }
};