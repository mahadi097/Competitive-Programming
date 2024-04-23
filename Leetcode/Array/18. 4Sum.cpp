struct custom_hash {
    static uint64_t splitmix64(uint64_t x) {
        // http://xorshift.di.unimi.it/splitmix64.c
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }

    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector <vector<int>> ans;
        unordered_map <int, vector<pair<int, int>>, custom_hash> pos;
        unordered_map <int, bool, custom_hash> done;
        map <vector<int>, bool> doneV;
        int n = nums.size();
        int mx = 2e9, mn = -2e9;

        for(int i = 0; i < n; i++) {
            for(int j = i+1; j < n; j++) {
                int sum = nums[i] + nums[j];
                pos[sum].push_back({i, j});
            }
        }

        for(auto p: pos) {
            int sum1 = p.first;
            long long sum22 = target - sum1;

            if(sum22 > mx or sum22 < mn) continue;

            int sum2 = sum22;

            if(pos[sum2].empty()) continue;
            if(done[sum1]) continue;

            done[sum1] = done[sum2] = 1;

            for(auto in1: p.second) {
                int i = in1.first, j = in1.second;

                for(auto in2: pos[sum2]) {
                    int p = in2.first, q = in2.second;

                    if(i == p or i == q or j == p or j == q) continue;

                    vector <int> v;

                    v.push_back(nums[i]);
                    v.push_back(nums[j]);
                    v.push_back(nums[p]);
                    v.push_back(nums[q]);

                    sort(v.begin(), v.end());

                    if(doneV[v]) continue;

                    doneV[v] = 1;
                    ans.push_back(v);
                }
            }
        }

        return ans;
    }
};
