class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int ans = 0, sum = 0;
        unordered_map <int, int> f;
        
        f[0] = 1;
        for(int num: nums) {
            sum += num;
            ans += f[sum-k];
            f[sum]++;
        }

        return ans;
    }
};