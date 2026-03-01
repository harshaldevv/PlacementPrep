class Solution {
public:
    bool isAnagram(string s, string t) {

        if(s.size() != t.size()){
            return false;
        }

        

        // vector<int> v(26, 0);

        // for(int i = 0 ; i < s.size(); i++){
        //     v[ s[i] - 'a']++;
        //     v[ t[i] - 'a']--;
        // }

        // // eventually all buckets should be zero
        // for(auto &x: v){
        //     if(x != 0){
        //         return false;
        //     }
        // }

        // return true;



        //  if(s.size() != t.size()){
        //     return false;
        // }

        // sort(s.begin(), s.end());
        // sort(t.begin(), t.end());

        // int l1 = 0;
        // int l2 = 0;
        // for(int i = 0 ; i < s.size(); i++){
        //     if(s[i] != t[i]){
        //         return false;
        //     }
        // }

        // return true;


        unordered_map<char, int> mp;
        for(auto &x: s){
            mp[x]++;
        }

        for(auto &x: t){
            if(mp.find(x) == mp.end()){
                return false;
            }
            else{
                mp[x]--;
                if(mp[x] == 0){
                    mp.erase(x);
                }
            }
        }

        return true;




        
    }
};