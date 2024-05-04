class Solution {
public:
    int findMaxK(vector<int>& nums) {
        int ans = -1;
        unordered_map <int, bool> st;
        for(auto num: nums) {
            if(st[-num]) ans = max(ans, max(num, -num));
            st[num] = 1;
        }

        return ans;
    }
};