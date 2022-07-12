class Solution {
public:
    int getPivot(vector<int> &arr){
        int n = arr.size();
        int l = 0;
        int r = n -1;
        
        while(l <= r ){
            
            if(arr[l ] <= arr[r]){
                return l;
            }
            
            int mid = l + (r-l)/2;
            
            int prev = (mid -1 + n)%n;
            int next = (mid +1 ) %n;
            
            if(arr[mid ] <= arr[prev] && arr[mid] <= arr[ next ]){
                return mid;
            }
            else if(arr[l] <= arr[mid]){
                // go in right half
                l = mid + 1;
            }
            else{
                r = mid -1;
            }
        }
        
        return 0;
    }
    
    int BS(vector<int> &arr, int l, int r, int target){
        while(l<=r){
            int mid = l + (r-l)/2;
            
            if(arr[mid] == target){
                return mid;
            }
            else if(arr[mid] < target){
                // go right
                l = mid +1;
            }
            else{
                r = mid -1;
            }
        }
        
        return -1;
    }
    int search(vector<int>& nums, int target) {
        
        // rotated sorted array --> means find pivot sabse pehle toh
        int pivot = getPivot(nums);
        cout << "pivot = "  << pivot << endl;
        
        
        int ans = BS(nums, 0, pivot -1, target);
        
        if(ans == -1){
            return BS(nums, pivot, nums.size() -1, target);
        }
        else{
            return ans;
        }
        
    }
};