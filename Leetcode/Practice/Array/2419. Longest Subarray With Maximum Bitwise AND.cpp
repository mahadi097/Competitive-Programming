class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int ans = 0, c = 0;

        for(int i = 0; i < nums.size(); i++) {
            int j = i, cc = 0;
            while(j < nums.size() and nums[j] == nums[i]) j++, cc++;
            if(nums[i] > ans) ans = nums[i], c = cc;
            else if(nums[i] == ans) c = max(c, cc);
            i = j-1;
        }

        return c;
    }
};