class Solution {
private:
    bool getBit(int x, int i) {
        return (x & (1 << i));
    }

public:
    int minOperations(vector<int>& nums, int k) {
        int minOp = 0, xorSum = 0;
        
        for(auto num: nums) xorSum ^= num;

        for(int i = 29; i >= 0; i--) {
            minOp += (getBit(k, i) != getBit(xorSum, i));
        }

        return minOp;
    }
};