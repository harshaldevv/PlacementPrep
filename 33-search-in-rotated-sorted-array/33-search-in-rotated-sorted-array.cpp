class Solution {
public:
    int getPivot(vector<int> &arr){
        int n = arr.size();
        int l =0;
        int r = n-1;
        
        while(l<=r){

            if(arr[l] <= arr[r]){
                return l;
            }
            
            int mid = l + (r-l)/2;
            
            int prev = (mid -1 + n )%n;
            int next = (mid+1)%n;
            
            if(arr[mid] <= arr[prev] && arr[mid] <= arr[prev]){
                return mid;
            }
            // go in unsorted part now
            else if(arr[l] <= arr[mid]){
                l = mid +1;
            }
            else{
                r = mid -1;
            }
        }
        
        return -1;
    }
    int BS(int l, int r , vector<int> &arr, int target ){
        while(l<=r){
            int mid = l + (r-l)/2;
            
            if(arr[mid] == target){
                return mid;
            }
            else if(arr[mid] > target){
                r = mid -1;
            }
            else{
                l = mid +1;
            }
        }
        
        return -1;
    }
    int search(vector<int>& nums, int target) {
        
        int pivot = getPivot(nums);
        cout << "pivot = " << pivot << endl;
        int ans = BS(0, pivot-1, nums, target );
        
        if(ans == -1){
            return BS(pivot, nums.size() - 1, nums, target);
        }
        else{
            return ans;
        }
        
    }
};