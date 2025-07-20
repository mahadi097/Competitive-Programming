class Solution {
public:
    int maximumLength(vector<int>& nums) {
        int r1 = 0, r2 = 0, r3 = 0;
        
        for(int num: nums) r1 += ((num & 1) == 0);
        r1 = max(r1, (int) nums.size()-r1);

        int parity = 0;
        for(int num: nums) {
            if((num & 1) == parity) {
                r2++;
                parity ^= 1;
            }
        }

        parity = 1;
        for(int num: nums) {
            if((num & 1) == parity) {
                r3++;
                parity ^= 1;
            }
        }

        return max({r1, r2, r3});
    }
};