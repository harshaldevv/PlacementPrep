class Solution {
public:
    int getPivot(vector<int> &arr){
        int l = 0;
        int r = arr.size()  -1;
        int n = arr.size();
        
        while(l <= r ){
            
            if(arr[l] <= arr[r]){
                return l;
            }
            
            int mid = l + (r-l)/2;
            int prev = (mid -1 + n)%n;
            int next = (mid + 1 )%n;
            
            if(arr[mid] <= arr[prev] && arr[mid] <= arr[next]){
                return mid;
            }
            
            if(arr[l] <= arr[mid]  ){
                // this is sorted
                // go in the right half
                l = mid +1;
            }
            else{
                r = mid -1;
            }
        }
        
        return 0;
    }
    
    int findMin(vector<int>& nums) {
        int pivot = getPivot(nums);
        
        return nums[pivot];
        
    }
};