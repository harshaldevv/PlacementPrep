class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        
        int start = 0;
        int end = letters.size()-1;
        char res = '#';
        
        while(start <= end){
            int mid = start + (end - start)/2;
            
            if(letters[mid] <= target){  
                // letter[mid] < target and then doing start = mid +1 was giving wrong ans
                // res = letters[mid];
                // end = mid -1;
                start = mid +1;
                
            }
            else{
                res = letters[mid];
                end = mid -1;
            }
        }
        
        if(res == '#'){
            res = letters[0];
        }
        
        return res;
        
    }
};