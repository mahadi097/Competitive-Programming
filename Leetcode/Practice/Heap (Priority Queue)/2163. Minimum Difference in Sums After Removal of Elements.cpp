class Solution {
public:
    long long minimumDifference(vector<int>& nums) {
        int n = nums.size();
        long long ans = LLONG_MAX;
        vector <long long> sumF(n, 0), sumS(n, 0);
        
        n /= 3;

        priority_queue <int> mx;
        for(int i = 0; i < n; i++) {
            mx.push(nums[i]);
            sumF[i] = i == 0 ? nums[i] : sumF[i-1] + nums[i];
        }
        for(int i = n; i <= 2*n-1; i++) {        
            int curMx = mx.top();
            
            if(curMx > nums[i]) {
                mx.pop();
                mx.push(nums[i]);
                sumF[i] = sumF[i-1] - curMx + nums[i];
            }
            else sumF[i] = sumF[i-1];
        }

        priority_queue <int, vector<int>, greater<int>> mn;
        for(int i = 3*n-1; i >= 2*n; i--) {
            mn.push(nums[i]);
            sumS[i] = i == 3*n-1 ? nums[i] : sumS[i+1] + nums[i];
        }
        for(int i = 2*n-1; i >= n; i--) {
            int curMn = mn.top();
            
            if(curMn < nums[i]) {
                mn.pop();
                mn.push(nums[i]);
                sumS[i] = sumS[i+1] - curMn + nums[i];
            }
            else sumS[i] = sumS[i+1];
        }

        for(int i = n-1; i <= 2*n-1; i++) ans = min(ans, sumF[i]-sumS[i+1]);

        return ans;
    }
};