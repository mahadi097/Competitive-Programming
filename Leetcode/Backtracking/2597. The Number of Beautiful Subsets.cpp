class Solution {
private:    
    int solve(int in, vector<int>& nums, int k, unordered_map<int, bool> &exist) {
        if(in == nums.size()) return 1;

        int r2 = 0, r1 = solve(in+1, nums, k, exist);

        int v = nums[in] - k;
        if(v <= 0 or !exist[v]) {
            exist[nums[in]] = 1;
            r2 = solve(in+1, nums, k, exist);
            exist[nums[in]] = 0;
        }

        return r1 + r2;
    }

public:
    int beautifulSubsets(vector<int>& nums, int k) {
        unordered_map<int, bool> exist;
        sort(nums.begin(), nums.end());
        return solve(0, nums, k, exist) - 1;
    }
};