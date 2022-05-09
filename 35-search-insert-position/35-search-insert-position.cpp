class Solution {
public:
    int searchInsert(vector<int>& arr, int target) {
        int start = 0;
        int end = arr.size() -1;
        
        while(start <= end){
            int mid = start + (end-start)/2;
            
            if(arr[mid] == target){
                return mid;
            }
            if(arr[mid] > target){
                //go left;
                end = mid -1;
            }
            else{
                start = mid +1;
            }
        }
        
        return 1+ end;
    }
};