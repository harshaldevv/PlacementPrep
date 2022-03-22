class Solution {
public:
    int minimumSum(int num) {
        
        vector<int> v;
        
        int x = num;
        while(x!=0){
            int r = x%10;
            v.push_back(r);
            x/=10;
        }
        
//         reverse(v.begin(), v.end());
        
//         int a = v[0];
//         int b = v[1];
//         int c = v[2];
//         int d = v[3];
        
        sort(v.begin(), v.end());
        
        int a = v[0]*10 + v[2];
        int b = v[1]*10 + v[3];
        
        return a+ b;
        
    }
};