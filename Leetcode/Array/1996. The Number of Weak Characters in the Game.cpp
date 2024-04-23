class Solution {
public:
    int numberOfWeakCharacters(vector<vector<int>>& properties) {
        int n = properties.size();

        sort(properties.begin(), properties.end(), [](vector <int> &x, vector <int> &y) {
            return x[0] < y[0];
        });

        vector <int> maxDef(n);

        maxDef[n-1] = properties[n-1][1];
        for(int i = n-2; i >= 0; i--) maxDef[i] = max(maxDef[i+1], properties[i][1]);

        int ans = 0;
        for(int i = 0, j = 1; j < n; ) {
            if(properties[j][0] > properties[i][0]) {
                if(maxDef[j] > properties[i][1]) ans++;

                i++;
                if(i == j) j++;
            }
            else j++;
        }

        return ans;
    }
};
