class Solution {
public:
    void sortColors(vector<int>& nums) {
        for(int i = 0; i < nums.size(); i++) {
            if(nums[i] == 0) {
                int j = i;
                while(j-1 >= 0 and nums[j-1] != 0) swap(nums[j-1], nums[j]), j--;
            }
        }

        for(int i = 0; i < nums.size(); i++) {
            if(nums[i] == 1) {
                int j = i;
                while(j-1 >= 0 and nums[j-1] == 2) swap(nums[j-1], nums[j]), j--;
            }
        }
    }
};