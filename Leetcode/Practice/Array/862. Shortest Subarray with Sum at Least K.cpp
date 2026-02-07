class Solution {
public:
    int shortestSubarray(vector<int>& nums, int k) {
        int n = nums.size(), ans = 1e9;

        deque <int> dq;
        dq.push_back(0);
        vector <long long> preSum(n+1, 0);

        for(int i = 0; i < n; i++) {
            if(nums[i] >= k) ans = 1;

            preSum[i+1] = preSum[i] + nums[i];

            while(!dq.empty() and preSum[dq.front()]+k <= preSum[i+1]) {
                ans = min(ans, (i+1) - dq.front() );
                dq.pop_front();
            }

            while(!dq.empty() and preSum[dq.back()] >= preSum[i+1]) dq.pop_back();
            dq.push_back(i+1);
        }

        if(ans == 1e9) ans = -1;

        return ans;
    }
};
