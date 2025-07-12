class Solution {
public:
    int matchPlayersAndTrainers(vector<int>& players, vector<int>& trainers) {

        int n1 = players.size();
        int n2 = trainers.size();

        sort(players.begin(), players.end());
        sort(trainers.begin(), trainers.end());

        int i = 0;
        int j = 0;

        int ans = 0;
        while(i<n1 && j < n2){
            if(players[i] <= trainers[j]){
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