class Solution {
public:
    int matchPlayersAndTrainers(vector<int>& players, vector<int>& trainers) {
        int ans = 0, i = 0, j = 0;

        sort(players.begin(), players.end());
        sort(trainers.begin(), trainers.end());

        while(i < players.size() and j < trainers.size()) {
            if(players[i] <= trainers[j]) ans++, i++, j++;
            else j++;
        }

        return ans;
    }
};