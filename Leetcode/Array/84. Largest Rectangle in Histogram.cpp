class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int ans = 0, n = heights.size();
        stack <int> pos;
        vector <vector<int>> res(n, vector<int>(2, 0));

        for(int i = 0; i < n; i++) {
            while(!pos.empty() and heights[pos.top()] >= heights[i]) pos.pop();

            res[i][0] = pos.empty() ? i+1 : i - pos.top();

            pos.push(i);
        }

        while(!pos.empty()) pos.pop();

        for(int i = n-1; i >= 0; i--) {
            while(!pos.empty() and heights[pos.top()] >= heights[i]) pos.pop();

            res[i][1] = pos.empty() ? n-i : pos.top() - i;

            pos.push(i);

            int area = (res[i][0] + res[i][1] - 1) * heights[i];
            ans = max(ans, area);
        }

        return ans;
    }
};
