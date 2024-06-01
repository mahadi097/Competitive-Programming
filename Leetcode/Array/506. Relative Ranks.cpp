class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        int n = score.size();
        vector<string> ans(n);
        vector<vector<int>> a(n, vector<int>(2));

        for(int i = 0; i < n; i++) {
            a[i][0] = score[i];
            a[i][1] = i;
        }

        sort(a.begin(), a.end(), [](vector<int> v1, vector<int> v2) {
            return v1[0] > v2[0];
        });

        for(int i = 0; i < n; i++) {
            int pos = a[i][1];
            
            switch(i) {
                case 0:
                    ans[pos] = "Gold Medal";
                    break;
                case 1:
                    ans[pos] = "Silver Medal";
                    break;
                case 2:
                    ans[pos] = "Bronze Medal";
                    break;
                default:
                    ans[pos] = to_string(i+1);
                    break;
            }
        }

        return ans;
    }
};