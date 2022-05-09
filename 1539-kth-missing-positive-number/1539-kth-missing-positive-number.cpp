class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        
        if( k < arr[0] ){
            return k;
        }
        
        int start = 0;
        int end = arr.size() -1;
        
        while(start <= end){
            int mid = start + (end-start)/2;
            
            if(arr[mid] - mid -1 >= k){
                // go left
                end = mid-1;
            }
            else{
                start = mid +1;
            }
        }
        
        return start + k;
        
    }
};