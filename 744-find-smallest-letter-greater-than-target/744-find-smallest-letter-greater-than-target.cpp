class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        // ceil of a number/ character
        
        int l = 0;
        int r = letters.size() -1;
        int mid ;
        char ans = '#';
        while(l<=r){
            mid = l + (r-l)/2;
            
            if(letters[mid] == target){
                l = mid +1; 
            }
            else if(letters[mid] < target ){
                // go right
                l = mid +1;
            }
            else{
                ans = letters[mid];
                //go left
                r = mid -1;
            }
        }
        
        if(ans == '#'){
            return letters[0];
        }
        else{
            return ans;
        }
    }
};