class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector <vector<int>> ans;
        unordered_map <int, int> f;
        map <pair<int, int>, int> done;

        for(auto v: nums) f[v]++;

        for(int i = 0; i < nums.size(); i++) {
            int v1 = nums[i];
            for(int j = i+1; j < nums.size(); j++) {
                int v2 = nums[j];
                int v3 = -(v1 + v2);

                if(done[{v1, v2}] or done[{v2, v1}]) continue;

                if(f[v3]) {
                    vector <int> v = {v1, v2, v3};
                    sort(v.begin(), v.end());

                    if(done[{ v[0], v[1] }]) continue;

                    done[{ v[0], v[1] }] = 1;

                    if(v3 == 0 and v1 == 0 and v2 == 0) {
                       if(f[0] >= 3) ans.push_back(v);
                        continue;
                    }
                    if(v3 != v1 and v3 != v2) ans.push_back(v);
                    else if((v3 == v1 or v3 == v2) and f[v3] >= 2 and v3 != 0) ans.push_back(v);
                }
            }
        }

        return ans;
    }
};

