class Solution {
public:
    
    int getpivot(vector<int> &arr){
        int n = arr.size();
        int start = 0;
        int end = n-1;
        
        while(start <= end){
            if(arr[start] <= arr[end]){
                return start;
            }
            
            int mid = start + ( end - start)/2;
            
            int prev = (mid -1 + n )%n;
            int next = (mid+1)%n;
            
            if(arr[mid] <= arr[prev] && arr[mid] <= arr[next]){
                return mid;
            }
            else if(arr[start] <= arr[mid]){
                // go in right unsorted half
                start = mid +1;
            }
            else{
                end = mid -1;
            }
        }
        
        return 0;
    }
    
    int BS(vector<int> &arr, int l, int r, int target){
        
        while(l<= r){
            int mid = l + (r-l)/2;
            if(arr[mid] == target){
                return mid;
            }
            else if(arr[mid] > target){
                ///go left 
                r = mid -1;
            }
            else{
                l = mid +1;
            }
        }
        
        return -1;
    }
    
    
    int search(vector<int>& nums, int target) {
        
        int pivot = getpivot(nums);
        cout << "pivot = " << pivot << endl;
        
        
        int ans = BS(nums, 0, pivot -1,target );
        
        if(ans == -1){
            return BS(nums, pivot, nums.size() -1, target);
        }
        else{
            return ans;
        }
        
    }
};