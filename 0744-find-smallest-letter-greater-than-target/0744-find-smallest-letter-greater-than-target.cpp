class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        char ans = letters[0];
        
        int l = 0;
        int r = letters.size()-1;
        
        while(l<=r){
            int mid = l + (r-l)/2;
            
            if(letters[mid] > target){
                ans = letters[mid];
                r = mid-1;
            }
            else{
                l = mid +1;
            }
        }
    
        return ans;
        
    }
};