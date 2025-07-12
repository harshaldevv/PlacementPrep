class Solution {
public:
    bool haveConflict(vector<string>& event1, vector<string>& event2) {

        string l1 = event1[0];
        string r1 = event1[1];

        string l2 = event2[0];
        string r2 = event2[1];

        return l1 <= r2 && l2 <= r1;
        
    }
};