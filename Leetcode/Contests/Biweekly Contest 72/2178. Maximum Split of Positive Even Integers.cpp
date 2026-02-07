class Solution {
public:
    vector<long long> maximumEvenSplit(long long finalSum) {
        vector <long long> v;
        if(finalSum%2 == 1) return v;


        for(long long x = 2, nowSum = 0;  nowSum < finalSum; x += 2) {
            if(x > (finalSum-nowSum)) {
                long long n = v.size();
                v[n-1] += (finalSum-nowSum);
                break;
            }
            else {
                v.push_back(x);
                nowSum += x;
            }
        }

        return v;
    }
};