class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        
        // basically finding peak element in the array
        
        int start = 0;
        int end = arr.size() -1;
        int n = arr.size();
        
        while(start <= end){
            int mid = start + (end- start)/2;
            
            if(mid >0 && mid < n-1){
                if(arr[mid]> arr[mid-1] && arr[mid] > arr[mid+1]){
                    return mid;
                }
                else if(arr[mid+1] > arr[mid-1]){
                    // go right
                    start = mid +1;
                }
                else{
                    end = mid -1;
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
                if(arr[n-1] > arr[n-2]){
                    return n-1;
                }
                else{
                    return n-2;
                }
            } 
        }
        
        return -1;
        
    }
};