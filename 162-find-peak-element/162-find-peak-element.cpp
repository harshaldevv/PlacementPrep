class Solution {
public:
    int findPeakElement(vector<int>& arr) {
        int n = arr.size();
        
        if(n == 1){
            return 0;
        }
        
        int l = 0;
        int r = n-1;
        
        
        while(l<=r){
            int mid = l + (r-l)/2;
            
            
            if(mid >0 && mid < n-1){
                
                if(arr[mid] > arr[mid-1] && arr[mid] > arr[mid+1]){
                    // this is our peak element
                    return mid;
                }
                else if(arr[mid] > arr[mid-1] ){
                    // we should go in the ahead direction 
                    l = mid +1;
                }
                else{
                    r = mid -1;
                }
            }
            else if(mid == 0){
                if(arr[1] >arr[0] ){
                    return 1;
                }
                else{
                    return 0;
                }
            }
            else if(mid == n-1){
                if(arr[n-2] > arr[n-1]){
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