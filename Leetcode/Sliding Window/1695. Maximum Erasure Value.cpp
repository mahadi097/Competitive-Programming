class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        int ans = 0;
        unordered_map <int, bool> st;

        for(int i = 0, j = 0, sum = 0; j < nums.size(); j++) {
            if(!st[nums[j]]) {
                st[nums[j]] = true;
                sum += nums[j];
                ans = max(ans, sum);
            }
            else {
                while(st[nums[j]] and i < j) {
                    st[nums[i]] = false;
                    sum -= nums[i];
                    i++;
                } 

                st[nums[j]] = true;
                sum += nums[j];
            }
        }

        return ans;
    }
};