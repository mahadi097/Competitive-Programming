class Solution {
private:
    void xorSum(int &xor_, char c) {
        int v = c - 'a';
        xor_ ^= (1 << v);
    }
public:
    long long wonderfulSubstrings(string word) {
        long long ans = 0;
        unordered_map <int, int> xorF; // xor frequency of cumulative sum
        xorF[0] = 1;
        int xor_ = 0;

        vector <int> subXor; // subarrays of xor needed
        subXor.push_back(0);
        for(int i = 0; i <= 9; i++) subXor.push_back(1<<i);

        for(auto c: word) {
            xorSum(xor_, c);

            for(auto sub: subXor) {
                int xorCum = xor_ ^ sub;
                ans += xorF[xorCum];    
            }
            xorF[xor_]++;
        }

        return ans;
    }
};