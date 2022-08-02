class Solution {
public:
    int binaryGap(int n) {
        
        int i = 31;
        int ans = 0;
        int j = -1;
        while(i>=0){
            if( (n & 1<<i ) !=0){
                j = i;
                break;
                // found msb -->aka first set bit
            }
            i--;
        }
        
        for( ; i >=0 ; i--){
            if( (n & 1<<i) != 0 ){
                ans = max(ans,j -i);
                j = i;
            }
        }
        
        return ans;
        
    }
};