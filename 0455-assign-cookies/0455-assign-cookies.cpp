class Solution {
public:
    int findContentChildren(vector<int>& greed, vector<int>& cookieSizes) {

        int n1 = greed.size();
        int n2 = cookieSizes.size();

        sort(greed.begin(), greed.end());
        sort(cookieSizes.begin(), cookieSizes.end());

        int i = 0;
        int j = 0;



        int ans = 0;
        while(i<n1 && j < n2){
            if(greed[i] <= cookieSizes[j]){
                ans++;
                i++;
                j++;
            }
            else{
                j++;
            }
        }

        return ans;
        
    }
};