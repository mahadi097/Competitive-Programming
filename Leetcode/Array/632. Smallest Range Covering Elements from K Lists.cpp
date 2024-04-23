class Solution {
public:
    unordered_map <int, int> f;
    set <int> listLen;

    void incList(int pos) {
        f[pos]++;
        if(f[pos] == 1) listLen.insert(pos);
    }

    void decList(int pos) {
        f[pos]--;
        if(f[pos] == 0) listLen.erase(pos);
    }

    vector<int> smallestRange(vector<vector<int>>& nums) {
        unordered_map <int, vector<int>> in;
        vector <int> r(2), val;
        int k = nums.size();

        r[0] = 0, r[1] = 1e9;

        int i = -1;
        for(auto list: nums) {
            i++;
            for(auto v: list) in[v].push_back(i), val.push_back(v);
        }

        sort(val.begin(), val.end());
        val.resize(distance(val.begin(),unique(val.begin(), val.end())));

        int st = 0, en = 0, n = val.size();
        for(auto pos: in[val[0]]) incList(pos);

        while(en < n) {
            if(listLen.size() == k) {
                if(val[en]-val[st] < r[1]-r[0]) r[0] = val[st], r[1] = val[en];

                for(auto pos: in[val[st]]) decList(pos);

                st++;
                if(st > en) {
                    en++;
                    if(en < n) for(auto pos: in[val[st]]) incList(pos);
                }
            }
            else {
                en++;
                if(en < n) for(auto pos: in[val[en]]) incList(pos);
            }
        }

        return r;
    }
};
