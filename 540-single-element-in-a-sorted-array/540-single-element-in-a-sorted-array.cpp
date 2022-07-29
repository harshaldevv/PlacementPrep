class Solution {
public:
    int singleNonDuplicate(vector<int>& arr) {
        
        // O(logn) approach
        int n = arr.size();
        
        if( n == 1){
            return arr[0];
        }
        
        int l = 0;
        int r = n-1;
        
        while(l<=r){
            int mid = l + (r-l)/2;
            
            if(mid >0 && mid < n-1){
                
                if(arr[mid] != arr[mid-1] && arr[mid] != arr[mid+1]){
                    return arr[mid];
                }
                
                if(mid %2 == 0){
                    // mid is even
                    if(arr[mid] == arr[mid+1]){
                        l = mid +1;
                    }
                    else{
                        r = mid -1;
                    }
                }
                else if( mid %2 != 0){
                    // mid is odd
                    if(arr[mid] == arr[mid-1]){
                        l = mid +1;
                    }
                    else{
                        r = mid-1;
                    }
                }
            }
            else if(mid == 0){
                if(arr[0] != arr[1]){
                    return arr[0];
                }
            }
            else if(mid == n-1){
                if(arr[n-1] != arr[n-2] ){
                    return arr[n-1];
                }
            }
        }
        
        return arr[l];
        
    }
};