class Solution {
private:
    bool check(int x, int pos) {
        return x & (1<<pos);
    }
public:
    vector<int> singleNumber(vector<int>& nums) {
        int xorXY = 0;
        for(int i = 0; i < nums.size(); i++) xorXY ^= nums[i];

        int oddBit;
        for(int i = 0; i <= 30; i++) {
            if(check(xorXY, i)) { oddBit = i; break; }
        }

        int xor_ = 0;
        for(int i = 0; i < nums.size(); i++) {
            if(check(nums[i], oddBit)) xor_ ^= nums[i];
        }

        return {xor_, xorXY^xor_};
    }
};