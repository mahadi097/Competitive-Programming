class Solution {
public:
    int countTriplets(vector<int>& arr) {
        int n = arr.size();
        unordered_map <int, int> f[n];

        for(int j = 0; j < n; j++) {
            int xor_ = 0;
            for(int k = j; k < n; k++) {
                xor_ ^= arr[k];
                f[j][xor_]++;
            }
        }

        int cnt = 0;
        for(int i = 0; i < n-1; i++) {
            int xor_ = 0;
            for(int j = i+1; j < n; j++) {
                xor_ ^= arr[j-1];
                cnt += f[j][xor_];
            }
        }

        return cnt;
    }
};