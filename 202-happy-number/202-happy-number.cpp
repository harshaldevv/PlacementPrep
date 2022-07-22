class Solution {
public:
    int next(int n){
       int sum = 0;
        while(n){
            int temp = n%10;
            sum += (temp*temp);
            n/=10;
        }
        
        return sum ; // this is our next number 
        
        
    }
    bool isHappy(int n) {
        // TC - O(n), SC - O(1)
        // floyd cycle detection technique
        
        int slow = next(n);
        int fast = next(next(n));
        
        while(slow != fast){
            slow = next(slow);
            fast = next(next(fast));
        }
        
        // collision ho gaya hai ab 
        // therefore check ab collison jo hua hai woh "1" pe hua hai ya nahi
        
        if (fast == 1){
            return true;
        }
        else{
            return false;
        }
        
        
//         // TC - O(n), SC - O(n)
//         unordered_set<int> s;
        
//         while(n != 1){
//             if(s.find(n) == s.end()){
//                 // not found in our set
//                 // therefore insert in the set
//                 s.insert(n);
//             }
//             else{
//                 // found in our set
//                 // aka cycle detected
//                 return false;
//             }
            
//             int sum = 0;
//             while(n){
//                 int temp = n%10;
//                 sum += (temp*temp);
//                 n/= 10;
//             }
            
//             n = sum;
//         }
        
        
//         return true;
    }
};