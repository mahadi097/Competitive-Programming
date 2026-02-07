class Solution {
public:
    vector <string> ans;
    map <char, vector<char>> v;

    vector<string> letterCombinations(string digits) {
        for(char i = '2', c = 'a'; i <= '9'; i++, c += 3) {
            char c3 = c + 3;

            for(char cc = c; cc < c3; cc++) v[i].push_back(cc);

            if(i == '7' or i == '9') {
                v[i].push_back(c3);
                c++;
            }
        }

         if(!digits.empty()) solve(digits, 0, "");

        return ans;
    }

    void solve(string &d, int pos, string s) {
        if(pos == d.size()) {
            ans.push_back(s);
            return;
        }

        int dd = d[pos];

        solve(d, pos+1, s+v[dd][0]);
        solve(d, pos+1, s+v[dd][1]);
        solve(d, pos+1, s+v[dd][2]);
        if(dd == '7' or dd == '9') solve(d, pos+1, s+v[dd][3]);
    }
};


