class Solution {
public:
    void sortColors(vector<int>& arr) {
        int low = 0;
        int high = arr.size() -1;
        
        int i = low; // i = mid pointer
        
        while( i <= high){
            if(arr[i] == 0){
                swap(arr[i], arr[low]);
                i++;
                low++;
            }
            else if(arr[i] == 1){
                i++;
            }
            else{
                // arr[i] == 2
                swap(arr[i], arr[high]);
                high--;
            }
        }
        
    }
};