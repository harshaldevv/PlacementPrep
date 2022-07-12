class Solution {
public:
    int findPeakElement(vector<int>& arr) {
        int l = 0;
        int r = arr.size() -1;
        int n = arr.size();
        
        if(n==1){
            //return arr[n-1];
            return 0;
        }
        while(l<=r){
            int mid = l  + (r-l)/2;
            
            if(mid > 0 && mid < n-1){
                // check here
                
                int prev = mid - 1;
                int nxt = mid + 1;
                
                if(arr[mid] > arr[prev] && arr[mid] > arr[nxt]){
                    return mid;
                }
                else if(arr[mid] > arr[prev]){
                    // go right
                    l = mid +1;
                }
                else{
                    r = mid -1; 
                }
            }
            else if(mid == 0){
                if(arr[0] > arr[1]){
                    return 0;
                }
                else{
                    return 1;
                }
            }
            else{
                if(arr[n-2] > arr[n-1] ){
                    return n-2;
                }
                else{
                    return n-1;
                }
            }
        }
        
        return -1;
    }
};