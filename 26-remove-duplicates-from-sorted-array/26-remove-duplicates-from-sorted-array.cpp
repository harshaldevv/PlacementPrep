class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        
        int curr = 0;
        for(int i = 1 ; i < nums.size() ; i++){
            if(nums[i] != nums[curr]){
                nums[curr+1] = nums[i];
                curr++;
            }
        }
        
        return curr +1 ; // +1 bcz curr toh indexing ke lie use ho raha hai and zero 
        // based indexing ha so yeah , isliye 1 based me lane ke lie +1 kar dia
        
    }
};