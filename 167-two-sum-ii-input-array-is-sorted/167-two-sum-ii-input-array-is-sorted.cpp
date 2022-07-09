class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        
        
        // Brute Force --> 2 for loops -> TC - O(n^2), SC - O(1)
        
        // Binary Search --> for every element e, find "target-e" in the SORTED array --> TC - O(nlogn), SC - O(1)
        
        // 2 ptr approach -> TC - O(n), SC - O(1)
        
        int i = 0;
        int j = numbers.size() -1;
        
        while(i< j){
            int a = numbers[i];
            int b = numbers[j];
            
            int sum = a+b;
            
            if(sum == target){
                return {i +1,j +1};  // +1 becuase 1 - based indexing
            }
            else if(sum> target){
                // go left
                j--;
            }
            else{
                i++;
            }
        }
        
        return {-1, -1};
        
    }
};