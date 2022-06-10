class Solution {
public:
    int findMin(vector<int>& arr) {
        int n = arr.size();
        
        int start = 0;
        int end = n-1;
        
        
        
        while(start<= end){
            
            if(arr[start] <= arr[end]){
                return arr[start];
            }
            
            int mid = start + (end-start)/2;
            
            int next = (mid +1)%n;
            int prev = (mid-1 +n)%n;
            
            if(arr[mid] <= arr[prev] && arr[mid] <= arr[next]){
                return arr[mid];
            }
            else if(arr[start] <= arr[mid]){
                //sorted
                // go in unsorted right half
                start = mid+1;
            }
            else{
                end = mid-1;
            }
        }
        
        return -1;
        
    }
};