class Solution {
public:
    int maxSum(vector<int>& nums) {
        sort(nums.begin(), nums.end(), [](int x, int y) {
            return x > y;
        });

        int ans = nums[0], sum = 0;
        unordered_map <int, bool> st;
        
        for(int num: nums) {
            if(st[num]) continue;
            
            st[num] = true;
            sum += num;
            ans = max(ans, sum);
        }

        return ans;
    }
};