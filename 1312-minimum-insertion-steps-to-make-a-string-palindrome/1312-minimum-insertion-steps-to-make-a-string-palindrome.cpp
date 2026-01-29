class Solution {
public:
    int LCS(string &s1, string &s2){
        int n1 = s1.size();
        int n2 = s2.size();

        
        vector<int> curr(n2+1, 0);
        vector<int> prev(n2+1, 0);

        // basecase sorted already

        for(int i = 1 ; i <= n1 ; i++){
            for(int j = 1 ; j<= n2 ; j++){
                if(s1[i-1] == s2[j-1]){
                    curr[j] = 1 + prev[j-1];
                }
                else{
                    curr[j] = max( prev[j], curr[j-1] );
                }
            }

            prev = curr;
        }

        return prev[n2];
    }
    int LPS(string s){
        string s1 = s;
        string s2 = s;

        int n = s.size();

        reverse(s2.begin(), s2.end());

        return LCS(s1, s2);



    }
    int minInsertions(string s) {

        return s.size() - LPS(s);
        
    }
};