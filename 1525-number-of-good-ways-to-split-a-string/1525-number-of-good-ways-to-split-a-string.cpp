class Solution {
public:
    int numSplits(string s) {
        
        int n = s.size();
        
        unordered_map< char , int> mp;

        
        vector<int> fwd(s.size(),-1);
        
        for(int i = 0 ; i < s.size() ; i++){
            mp[s[i]]++;
            fwd[i] = mp.size();
        }
        
        mp.clear();
        
        vector<int> backk(s.size() , -1);
        for(int i = s.size() -1. ; i >=0 ; i--){
            mp[s[i]]++;
            backk[i] = mp.size();
        }
        
//         for(int i = 0 ; i < backk.size() ; i++){
//             cout << "i = " <<  i << " , back[i] = " << backk[i];
//             cout << endl;
//         }
        
//         cout << endl;
        
        int ans = 0;
        
        for(int i = 1 ; i < s.size() ; i++ ){
            int leftCount = fwd[i-1];
            int rightCount = backk[i];
            
//             cout << "i = " << i << endl;
//             cout <<"Leftcount = " << leftCount << ", rightCount = "  << rightCount << endl;
            
            if(leftCount == rightCount){
                ans++;
            }
        }
        
        return ans;
        
        
        
    }
};