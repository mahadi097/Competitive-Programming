class Solution {
public:
    int n, mn = 0;
    string S;
    vector <string> ans;
    unordered_map <string, bool> done;

    bool check(int x, int pos) {
        return x & (1 << pos);
    }

    int set1(int x, int pos) {
        return x | (1 << pos);
    }

    vector<string> removeInvalidParentheses(string s) {
        S = s;
        n = S.size();

        int c = 0;
        for(int i = 0; i < n; i++) {
            if(S[i] != '(' and S[i] != ')') continue;
            if(S[i] == '(') c++;
            else {
                if(c == 0) mn++;
                else c--;
            }
        }
        mn += c;

        solve(0, 0, 0, 0);

        return ans;
    }

    void solve(int pos, int msk, int c, int t) {
        if(t > mn or c < 0) return;
        if(pos == n) {
            string s;
            bool ok[30] = {0};

            for(int i = 0; i < n; i++) if(check(msk, i)) ok[i] = 1;

            for(int i = n-1; i >= 0 and c > 0; i--) {
                if(S[i] == '(' and ok[i]) ok[i] = 0, c--, t++;
            }

            if(t > mn) return;

            for(int i = 0; i < n; i++) if(ok[i]) s.push_back(S[i]);

            if(!done[s]) {
                done[s] = 1;
                ans.push_back(s);
            }

            return;
        }

        if(S[pos] != '(' and S[pos] != ')') solve(pos+1, set1(msk, pos), c, t);
        else {
            solve(pos+1, msk, c, t+1);

            if(S[pos] == '(') solve(pos+1, set1(msk, pos), c+1, t);
            else solve(pos+1, set1(msk, pos), c-1, t);
        }
    }
};
