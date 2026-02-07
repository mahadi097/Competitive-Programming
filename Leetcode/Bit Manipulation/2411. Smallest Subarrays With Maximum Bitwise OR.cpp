class Solution {
private:
    bool isOne(int x, int pos) {
        return x & (1 << pos);
    }

    int setOne(int x, int pos) {
        return x | (1 << pos);
    }

public:
    vector<int> smallestSubarrays(vector<int>& nums) {
        int n = nums.size();
        vector <int> ans(n), mxOr(n);
        vector <stack<int>> mxOrBitPos(30);

        for(int i = n-1; i >= 0; i--) {
            mxOr[i] = (i == n-1) ? nums[i] : mxOr[i+1] | nums[i];

            for(int j = 0; j <= 30; j++) {
                if(isOne(nums[i], j)) mxOrBitPos[j].push(i);
            }
        }

        for(int i = 0; i < n; i++) {
            ans[i] = i;
            for(int j = 0; j <= 30; j++) {
                if(isOne(mxOr[i], j)) ans[i] = max(ans[i], mxOrBitPos[j].top());
                if(isOne(nums[i], j)) mxOrBitPos[j].pop();
            }
            ans[i] = ans[i] - i + 1;
        }

        return ans;
    }
};