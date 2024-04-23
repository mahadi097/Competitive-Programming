class Solution {
public:
    vector<int> sumEvenAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        vector <int> ans, state;
        int evenSum = 0, oddSum = 0;

        for(auto v: nums) {
            if(v & 1) oddSum += v;
            else evenSum += v;
        }

        for(auto v: queries) {
            int val = v[0], in = v[1];

            if(val & 1) {
                if(nums[in] & 1) {
                    oddSum -= nums[in];
                    evenSum += nums[in] + val;
                }
                else {
                    evenSum -= nums[in];
                    oddSum += nums[in] + val;
                }

            }
            else {
                if(nums[in] & 1) oddSum += val;
                else evenSum += val;
            }

            nums[in] += val;
            ans.push_back(evenSum);
        }

        return ans;
    }
};
