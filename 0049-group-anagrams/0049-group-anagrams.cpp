class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        
        // hci research
        
        unordered_map<string, vector<string>> anagrams; // store anagrams in a map
        
        for (string s : strs) {
            string sorted = s; 
            sort(sorted.begin(), sorted.end()); // sort the string to get its signature
            
            anagrams[sorted].push_back(s); // add the string to its anagram group
        }
        
        vector<vector<string>> result;
        for (auto it = anagrams.begin(); it != anagrams.end(); ++it) {
            result.push_back(it->second); // add each anagram group to the result
        }
        
        return result;
    }
};
