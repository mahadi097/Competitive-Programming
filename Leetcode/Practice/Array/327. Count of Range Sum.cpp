#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;

typedef tree<pair <long long, long long>, null_type, less<pair <long long, long long>>, rb_tree_tag, tree_order_statistics_node_update> ost; ///OST MEANS ORDERED SET
#define fbo     find_by_order ///FINDING OUT WHAT VALUE IS IN X'TH INDEX. IT RETURNS A POINTER.
#define ook     order_of_key ///FINDING OUT THE INDEX WHERE VALUE X IS. IF IT ISN'T PRESENT THEN IT'LL RETURN THE INDEX OF FIRST STRICTLY GREATER ELEMENT.


class Solution {
public:
  int countRangeSum(vector<int>& nums, int lower, int upper) {
    ost preSum;
    int ans = 0, c = 0;
    long long x, y, sum = 0;
    preSum.insert({sum, c});

    for(int i = 0; i < nums.size(); i++) {
        sum += nums[i];

        if(sum > upper) {
            x = sum - upper;
            y = sum - lower;
        }
        else if(sum >= lower and sum <= upper) {
            x = upper - sum;
            x = -x;
            y = sum - lower;
        }
        else {
            x = lower - sum;
            y = upper - sum;
            x = -x, y = -y;
            swap(x, y);
        }

        int r1 = preSum.ook({x, -1});
        int r2 = preSum.ook({y, c+1});

        if(r1 == preSum.size() or r1 >= r2) r1 = r2 = 0;

        ans += (r2 - r1);

//        cout << i << " " << sum << " " << r1 << " " << r2 << " " << x << " " << y << endl;

        preSum.insert({sum, ++c});
    }

    return ans;
  }
};


