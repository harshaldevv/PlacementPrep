class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        char res = '#';
        
        int n = letters.size();
        int start = 0;
        int end = n-1;
        
        while(start <= end){
            int mid = start + ( end-start)/2;
            
            if(letters[mid] == target){
                // go right
                start = mid +1;
            }
            else if(letters[mid] < target){
                //go right
                start = mid+1;
            }
            else{
                res= letters[mid];
                end = mid -1;
            }
        }
        
        if(res == '#'){
            res = letters[0];
        }
        return res;
    }
};