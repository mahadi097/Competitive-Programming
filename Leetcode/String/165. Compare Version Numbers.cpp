class Solution {
public:
    int stringToInt(string s) {
   	    int st = s.size(), v = 0;
      	for(int i = 0; i < s.size(); i++) {
            if(s[i] >= '1' and s[i] <= '9') { st = i; break; }
        }

        if(st == s.size()) return 0;

        for(int i = st; i < s.size(); i++) {
            v = (v * 10) + (s[i] - '0');
        }

        return v;
    }

    int compareVersion(string version1, string version2) {
        vector <int> r1, r2;

        for(int i = 0; i < version1.size(); i++) {
            if(version1[i] == '.') continue;

            int j = i;
            string s;
            while(j < version1.size() and version1[j] >= '0' and version1[j] <= '9') s.push_back(version1[j]), j++;

            i = j-1;

            int v = stringToInt(s);
            r1.push_back(v);
        }

        for(int i = 0; i < version2.size(); i++) {
            if(version2[i] == '.') continue;

            int j = i;
            string s;
            while(j < version2.size() and version2[j] >= '0' and version2[j] <= '9') s.push_back(version2[j]), j++;

            i = j-1;

            int v = stringToInt(s);
            r2.push_back(v);
        }

        int sz = max(r1.size(), r2.size());

        while(r1.size() < sz) r1.push_back(0);
        while(r2.size() < sz) r2.push_back(0);

        for(int i = 0; i < sz; i++) {
            if(r1[i] < r2[i]) return -1;
            else if(r1[i] > r2[i]) return 1;
        }

        return 0;
    }
};


