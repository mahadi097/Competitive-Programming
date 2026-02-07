class Solution {
public:
    int specialArray(vector<int>& nums) {
        sort(nums.begin(), nums.end(), [](int v1, int v2) {
            return v1 > v2;
        });

        int n = nums.size();
        for(int i = 0; i < n; i++) {            
            int x = i+1, nextVal = (i == n-1) ? -1 : nums[i+1];

            if(nums[i] >= x and nextVal < x) return x;
        }

        return -1;
    }
};