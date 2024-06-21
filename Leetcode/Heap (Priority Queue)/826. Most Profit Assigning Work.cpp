class Solution {
private:
    struct Job {
        int d, p;
        Job(int difficulty, int profit): d(difficulty), p(profit) {}
    };

public:
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
        auto compare = [](const Job& j1, const Job& j2) {
            return j1.d > j2.d;
        };

        priority_queue<Job, vector<Job>, decltype(compare)> jobs;
        for(int i = 0; i < profit.size(); i++) jobs.push(Job(difficulty[i], profit[i]));

        sort(worker.begin(), worker.end());

        int mxProfit = 0, mxCurrent = 0;
        for(auto w: worker) {
            while(!jobs.empty() and w >= jobs.top().d) {
                mxCurrent = max(mxCurrent, jobs.top().p);
                jobs.pop();
            }
            mxProfit += mxCurrent;
        }

        return mxProfit;
    }
};