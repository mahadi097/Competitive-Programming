class Solution {
public:
    int countHillValley(vector<int>& nums) {
        int ans = 0;
        
        for(int i = 0; i < nums.size(); i++) {
            if(i > 0 and nums[i] == nums[i-1]) continue; 

            int left = -1, right = -1;
            
            for(int j = i-1; j >= 0; j--) {
                if(nums[j] != nums[i]) { left = nums[j]; break; }
            }

            for(int j = i+1; j < nums.size(); j++) {
                if(nums[j] != nums[i]) { right = nums[j]; break; }
            }

            if(left == -1 or right == -1) continue;
            if((nums[i] > left and nums[i] > right) or (nums[i] < left and nums[i] < right)) ans++;
        }

        return ans;
    }
};