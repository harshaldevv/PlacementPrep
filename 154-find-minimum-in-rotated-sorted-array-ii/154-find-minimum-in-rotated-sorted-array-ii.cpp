class Solution {
public:
    int findMin(vector<int>& arr) {
        int n = arr.size();
        int start = 0;
        int end = n -1;
        
        if(n==1){
            // return arr[n-1];
            return arr[0]; // one element only
        }
        
        
        
        while(start <= end){
            
            int mid = start + (end-start)/2;
            

            if(arr[mid] > arr[end]){
                //this is unsorted (right) part
                start = mid+1;
            }
            else if (arr[mid] < arr[end]){
                // this is sorted part
                // go in unsorted left half
                end = mid ;
            }
            else{
                end--;
            }
        }
        return arr[start];
        
    }
};