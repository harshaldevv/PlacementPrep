class Solution {
public:
    string getPermutation(int n, int k) {
        vector<int> numbers;
        for(int i = 1 ; i <= n ; i++){
            numbers.push_back(i);
        }
        
        int f = 1;
        vector<int> fact;
        fact.push_back(1);
        for(int i = 1 ; i <= n ; i++){
            f*=i;
            // cout<< "f = " << f << endl;
            fact.push_back(f);
        }
        // cout <<"numb --" << endl;
        // for(auto x : numbers){
        //     cout << x << " ";
        // }
        
//         cout << endl;
//         cout <<"fact --" << endl;
//         for(auto x : fact){
//             cout << x << " ";
//         }
        
        
        k--;
        
        string ans = "";
        
        while(n>0){
            
            int factorial = fact[n-1];
            
            int index = k/factorial;
            // cout << "index = " << index << endl;
            ans+= to_string(numbers[index]);
            
            numbers.erase(numbers.begin() + index);
            n--;
            k=k%factorial;

        }
        
        return ans;

    }
};