class Solution {
public:
    bool checkIfExist(vector<int>& arr) {
        
        unordered_set<int> s;
        
        // one  pass;  -> 2 pass would be ki pehle sako set me daaldo then 
        unordered_map<int, int> mp;
        for(int i = 0 ; i < arr.size() ; i++){
            mp[arr[i]]++;
        }
        
        for(int i = 0; i < arr.size() ; i++){
            if(arr[i] != arr[i]*2){
                if(mp.find(arr[i]*2) != mp.end()){
                    return true;
                }
            }
            else if(arr[i] == 0){
                if(mp[arr[i]] > 1){
                    return true;
                }
            }
        }
        
        return false;
        

//         for(int i = 0 ; i < arr.size() ; i++){
//             if(s.count(arr[i]*2) > 0 || (arr[i] %2 == 0 && s.count(arr[i]/2) >0 )){
//                 return true;
//             }
//             s.insert(arr[i]);
//         }
        
// //         the reason we also check for i / 2 is because we may have an array like 
// //         [7,1,14,11] and if we just said n * 2 in seen, 14 isn't in seen yet so it would 
// //         return false instead of true. So when we get to 14, 7 is already in it so our 
// //         i/2 check will return True. That's why it can be done in one pass
            
                
//         return false;
        
    }
};