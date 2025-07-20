class Solution {
public:
    int maxEvents(vector<vector<int>>& events) {
        sort(events.begin(), events.end());

        int ans = 0;
        priority_queue<int, vector<int>, greater<int>> pq;
        for(int d = 1, i = 0; d <= 1e5; d++) {
            while(i < events.size() and events[i][0] <= d) {
                pq.push(events[i][1]);
                i++;
            }

            while(!pq.empty() and pq.top() < d) pq.pop();

            if(!pq.empty()) {
                pq.pop();
                ans++;
            }
        }

        return ans;
    }
};