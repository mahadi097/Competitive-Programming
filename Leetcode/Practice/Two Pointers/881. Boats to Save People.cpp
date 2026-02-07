class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        int n = people.size();
        int ans = n;

        sort(people.begin(), people.end());

        int st = 0;
        for(int en = n-1; en > st; en--) {
            if(people[en]+people[st] <= limit) ans--, st++;
        }

        return ans;
    }
};