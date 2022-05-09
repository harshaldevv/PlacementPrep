class Solution {
public:
    bool isPerfectSquare(int num) {
        int start = 1;
        int end = num;
        
        while(start <= end){
            int mid = start + (end-start)/2;
            
            if(mid  == (float)num/mid){
                return true;
            }
            if(mid > (float)num/mid){
                // go left
                end = mid -1;
            }
            else{
                start = mid +1;
            }
        }
        
        return false;
        
    }
};