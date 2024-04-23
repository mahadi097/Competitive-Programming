class Solution {
public:
    int maximumScore(vector<int>& nums, int k) {
        int n = nums.size();
        stack <int> pos;
        vector <vector<int>> mn(n, vector<int>(2));

        for(int i = 0; i < n; i++) {
            while(!pos.empty() and nums[pos.top()] >= nums[i]) pos.pop();

            mn[i][0] = pos.empty() ? 0 : pos.top() + 1;

            pos.push(i);
        }
        while(!pos.empty()) pos.pop();

        for(int i = n-1; i >= 0; i--) {
            while(!pos.empty() and nums[pos.top()] >= nums[i]) pos.pop();

            mn[i][1] = pos.empty() ? n-1 : pos.top() - 1;

            pos.push(i);
        }

        int ans = 0;
        for(int i = 0; i < n; i++) {
            if(k >= mn[i][0] and k <= mn[i][1]) ans = max(ans, nums[i] * (mn[i][1] - mn[i][0] + 1));
        }

        return ans;
    }
};

