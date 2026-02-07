class Solution {
public:
    int maxOr = 0;

    int countMaxOrSubsets(vector<int>& nums) {
        for(int num: nums) maxOr |= num;

        return countSubset(0, 0, nums);
    }

    int countSubset(int pos, int curOr, vector<int> &nums) {
        if(pos == nums.size()) return curOr == maxOr;

        return countSubset(pos+1, curOr, nums) + countSubset(pos+1, curOr | nums[pos], nums);
    }
};