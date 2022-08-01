class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        
        int n1 = nums1.size();
        int n2 = nums2.size();
        
        if(n1>n2){
            return findMedianSortedArrays(nums2, nums1);
        }
        
        int length = n1 + n2 ;
        
        int l = 0;
        int r = n1;
        
        while(l<=r){
            int mid = l + (r-l)/2;
            
            int cut1 = mid;
            int cut2 = (length+1)/2 - cut1;
            
            int l1, l2, r1, r2;
         
            
            l1 = cut1 == 0 ? INT_MIN : nums1[cut1-1] ;
            l2 = cut2 == 0 ? INT_MIN : nums2[cut2-1] ;
            
            r1 = cut1 == n1 ? INT_MAX : nums1[cut1] ;
            r2 = cut2 == n2 ? INT_MAX : nums2[cut2] ;
            
            if(l1<=r2 && l2 <= r1){
                // if even
                if(length %2 == 0){
                    double ans = max(l1, l2) + min(r1, r2);
                    return ans/2;
                }
                else{
                    return (double)(max(l1, l2));
                }
                
            }
            else if(l1>r2){
                // make cut1 go left
                r = mid -1;
            }
            else{
                // l2 > r1
                l = mid +1;
            }
        }
        
        return 0.0;
        
    }
};