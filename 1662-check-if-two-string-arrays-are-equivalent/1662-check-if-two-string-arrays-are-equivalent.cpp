class Solution {
public:
    bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) {
        
        int w1 = 0, w2 = 0, p1 = 0, p2 = 0;
        
        while(w1 < word1.size() && w2 < word2.size()){

            string str1 = word1[w1];
            string str2 = word2[w2];
            
            char c1 = str1[p1];
            char c2 = str2[p2];
            
            if(c1 != c2){
                return false;
            }
            
            if(p1 == str1.size() -1 ){
                p1 = 0;
                w1++;
            }
            else{
                p1++;
            }
            
            if(p2 == str2.size() -1 ){
                p2 = 0;
                w2++;
            }
            else{
                p2++;
            }
        }
        
        
        return w1 == word1.size() && w2 == word2.size(); 
        // make sure we've reached the end of both the vectors; 
        // tabhi true hoga else toh false hoga
        
    }
};