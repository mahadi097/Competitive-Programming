class Solution {
public:
    int longestPalindrome(string s) {
        vector<int> f(52, 0);
        for(auto c: s) {
            if(c >= 'A' and c <= 'Z') f[c-'A']++;
            else f[c-'a'+26]++;
        }

        int ans = 0, odd = 0;
        for(int i = 0; i < 52; i++) {
            ans += (f[i] - (f[i] % 2));
            if(f[i]%2) odd = 1;
        }
        ans += odd;

        return ans;
    }
};