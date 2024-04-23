class Solution {
public:
    int maxResult(vector<int>& nums, int k) {
        int n = nums.size();

        multiset <int, greater<int>> lastK;
        vector <int> mxSum(n);

        for(int i = 0; i < nums.size(); i++) {
            if(i == 0) {
                mxSum[i] = nums[i];
                lastK.insert(mxSum[i]);
                continue;
            }

            int mx = *lastK.begin();
            mxSum[i] = mx + nums[i];

            lastK.insert(mxSum[i]);

            if(lastK.size() > k) lastK.erase(lastK.find(mxSum[i-k]));
        }

        return mxSum[n-1];
    }
};
