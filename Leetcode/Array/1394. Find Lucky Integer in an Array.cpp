class Solution {
public:
    int findLucky(vector<int>& arr) {
        vector <int> f(501, 0);

        for(int i = 0; i < arr.size(); i++) f[arr[i]]++;

        int ans = -1;
        for(int i = 0; i < arr.size(); i++) {
            if(f[arr[i]] == arr[i]) ans = max(ans, arr[i]);
        }

        return ans;
    }
};