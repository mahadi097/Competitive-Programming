class MajorityChecker {
public:
    vector <int> a;
    unordered_map <int, int> f;
    unordered_map <int, vector<int>> fV, posV;

    MajorityChecker(vector<int>& arr) {
        a = arr;
        for(int i = 0; i < a.size(); i++) {
            int v = a[i];
            f[v]++;

            fV[f[v]].push_back(v);
            posV[v].push_back(i);
        }
    }

    int query(int left, int right, int threshold) {
        int ans = -1;

    	if(right-left-1 <= 100) {
            unordered_map <int, int> ff;

            for(int i = left; i <= right; i++) {
                int v = a[i];
                ff[v]++;
                if(ff[v] == threshold) { ans = v; break;}
            }
        }
        else {
            for(auto v: fV[threshold]) {
                int r1 = lower_bound(posV[v].begin(), posV[v].end(), left) - posV[v].begin();
                int r2 = upper_bound(posV[v].begin(), posV[v].end(), right) - posV[v].begin();

                if(r2-r1 >= threshold) { ans = v; break;}
            }
        }

        return ans;
    }
};

/**
 * Your MajorityChecker object will be instantiated and called as such:
 * MajorityChecker* obj = new MajorityChecker(arr);
 * int param_1 = obj->query(left,right,threshold);
 */


