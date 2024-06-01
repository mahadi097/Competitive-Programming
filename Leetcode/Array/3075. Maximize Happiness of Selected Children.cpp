class Solution {
public:
    long long maximumHappinessSum(vector<int>& happiness, int k) {
        long long ans = 0;
        sort(happiness.begin(), happiness.end(), [](int a, int b) {
            return a > b;
        });

        int dec = 0;
        for(int i = 0; i < k; i++) ans += max(0, happiness[i]-dec++);

        return ans;
    }
};