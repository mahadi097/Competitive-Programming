class Solution {
public:
    bool judgeSquareSum(int c) {
        for(int i = 0; (long long) i*i <= c; i++) {
            int jj = c - i*i;
            int j = sqrt(jj);
            if(j*j == jj) return true;
        }
        return false;
    }
};