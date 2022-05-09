class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        // find ceil of a number/alphabet
        
        int n = letters.size();
        int start = 0;
        int end = n-1;
        
        char res = '#';
        
        while(start <= end){
            int mid = start + (end-start)/2;
            
            if(letters[mid] == target){
                //go right 
                start = mid+1;
            }
            else if(letters[mid] > target){
                //go left
                res = letters[mid];
                end = mid-1;
            }
            else{
                start = mid+1;
            }
        }
        
        
        if(res == '#'){
            res = letters[0];
        }
        
        return res;
    }
};