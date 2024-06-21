class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        vector<int> in(1001, -1);
        for(int i = 0; i < arr2.size(); i++) in[arr2[i]] = i;

        sort(arr1.begin(), arr1.end(), [&in](int x, int y) {
            if(in[x] != -1 and in[y] != -1) return in[x] < in[y];
            else if(in[x] != -1) return true;
            else if(in[y] != -1) return false;
            else return x < y;
        });

        return arr1;
    }
};