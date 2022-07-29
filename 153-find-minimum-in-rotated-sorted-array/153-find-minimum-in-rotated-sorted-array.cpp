class Solution {
public:
    
    int getPivot(vector<int> &arr){
        int n = arr.size();
        int l = 0;
        int r = arr.size() -1;
        
        while(l<=r){
            
            if(arr[l] <= arr[r]){
                return l;
            }
            
            int mid = l + (r-l)/2;
            
            int prev = (mid -1 + n )%n;
            int next = (mid +1 )%n;
            
            // pivot element would be smaller than both of its neighbours
            if(arr[mid] <= arr[prev] && arr[mid] <= arr[next]){
                return mid;
            }
            
            // else now go in the unsorted half
            if(arr[l] <= arr[mid]){
                // this half is sorted
                // go in the unsorted half
                l = mid +1;
            }
            else{
                r = mid -1;
            }
        }
        
        return -1; // you can return l or return 0 --> both of them work
    }
    int findMin(vector<int>& nums) {
        // rotated sorted array --> means pehle pivot nikalo
        
        int piv = getPivot(nums);
        
        return nums[piv];
        
    }
};