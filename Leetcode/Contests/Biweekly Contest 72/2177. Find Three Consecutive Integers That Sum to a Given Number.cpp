class Solution {
public:
    vector<long long> sumOfThree(long long num) {
        vector <long long> v;

        if(num%3 != 0) return v;

        long long x = num / 3;
        v.push_back(x-1);
        v.push_back(x);
        v.push_back(x+1);

        return v;
    }
};