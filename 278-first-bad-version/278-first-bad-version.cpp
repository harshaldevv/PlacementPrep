// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        int start = 0;
        int end = n;
        
        int res = -1;
        while(start <= end){
            int mid = start + (end-start)/2;
            
            if(isBadVersion(mid)== true){
                //go left
                res = mid;
                end = mid -1;
            }
            else{
                // false ayega
                // go right
                start = mid+1;
            }
        }
        
        return res;
    }
};