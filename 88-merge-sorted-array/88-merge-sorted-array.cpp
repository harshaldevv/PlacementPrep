class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
       if(n == 0){
           return ;
       }
        
        if(m == 0){
            //copy all elements from nums2 to nums1
            for(int i = 0 ; i < nums2.size() ; i++){
                nums1[i] = nums2[i];
            }
            return ;
        }
        
        //start from peeche
        
        int i = m-1;
        int j = n-1;
        int k = m+n -1;
        
        while(i >= 0 && j >= 0){
            if(nums2[j] > nums1[i] ){
                nums1[k] = nums2[j];
                k--;
                j--;
            }
            else{
                nums1[k] = nums1[i];
                k--;
                i--;
            }
        }
        
        while(j >= 0){
            // keep copying 
            nums1[k] = nums2[j];
            k--;
            j--;
        }
        
        return ;
        
    }
};