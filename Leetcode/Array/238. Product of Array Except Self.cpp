class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector <int> pre(n), suf(n), ans(n);

        for(int i = 0; i < n; i++) pre[i] = (i == 0) ? nums[i] : pre[i-1] * nums[i];
        for(int i = n-1; i >= 0; i--) suf[i] = (i == n-1) ? nums[i] : suf[i+1] * nums[i];

        for(int i = 0; i < n; i++) ans[i] = (i == 0) ? suf[i+1] : (i == n-1) ? pre[i-1] : pre[i-1] * suf[i+1];

        return ans;
    }
};
