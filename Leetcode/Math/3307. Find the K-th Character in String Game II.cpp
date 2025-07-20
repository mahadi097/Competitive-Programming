class Solution {
public:
    char kthCharacter(long long k, vector<int>& operations) {
        vector <long long> pow2(61, 0);
        
        pow2[0] = 1;
        for (int i = 1; i <= 60; i++) pow2[i] = pow2[i-1] * 2;

        int c = 0, ln = operations.size();
        for(int i = ln; i >= 1; i--) {
            if(i > 60 or pow2[i]/2 >= k) continue;

            k -= (pow2[i] / 2);

            c += operations[i-1];
        }

        char ans = 'a' + (c % 26);

        return ans;
    }
};