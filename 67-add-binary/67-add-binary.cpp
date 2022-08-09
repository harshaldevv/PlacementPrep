class Solution {
public:
    string addBinary(string a, string b) {
        if(a.size() < b.size()){
            return addBinary(b,a);
        }
        
        // assuming A's length > B's length
        
        int c = 0;
        
        int p1 = a.size() -1;
        int p2 = b.size()-1;
        
        string ans = "";
        
        while(p1>=0 || p2>=0 || c ==1 ){

            int temp = 0;
            
            temp+=c;
            
            if(p1>=0){
                temp += (a[p1] -'0');
                p1--;
            }
            
            if(p2 >=0){
                temp+= (b[p2] -'0');
                p2--;
            }
            
            ans += to_string(temp%2);
            c = temp/2;
            
        }
        if(c >0){
            ans.push_back(c);
        }
        
        reverse(ans.begin(), ans.end());
        
        return ans;
        
    }
};