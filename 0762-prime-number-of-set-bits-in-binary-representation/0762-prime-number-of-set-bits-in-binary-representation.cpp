class Solution {
public:

    int countSetBits(int n){
        return __builtin_popcount(n);
    }

    unordered_set<int> getPrimeMap(){
        unordered_set<int> primeMap;
        primeMap.insert(2);
        primeMap.insert(3);
        primeMap.insert(5);
        primeMap.insert(7);
        primeMap.insert(11);
        primeMap.insert(13);
        primeMap.insert(17);
        primeMap.insert(19);
        primeMap.insert(23);
        primeMap.insert(29);
        return primeMap;
    }


    int countPrimeSetBits(int left, int right) {

        int ans = 0;
        unordered_set<int> primeMap = getPrimeMap();

        for(int i =  left ; i <= right ; i++){
            int setBits = countSetBits(i);
            if(primeMap.find(setBits) != primeMap.end()){
                ans++;
            }
        }
        

        return ans;
    }
};