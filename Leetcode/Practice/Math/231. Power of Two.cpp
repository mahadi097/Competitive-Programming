class Solution {
public:
    bool isPowerOfTwo(int n) {
        if (n == 0) return false;
        
        while(n != 1) {
            int nowN = n / 2;
            if(nowN * 2 != n) return false;
            n = nowN;
        }

        return true;
    }
};