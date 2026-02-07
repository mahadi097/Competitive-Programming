class Solution {
public:
    static bool cmp(string s1, string s2) {
        return s1.size() > s2.size();
    }

    int longestStrChain(vector<string>& words) {
        int ans = 1;
        int n = words.size();

//        sort(words.begin(), words.end(), cmp);
        sort(words.begin(), words.end(), [](string s1, string s2) {
            return s1.size() > s2.size();
        });

        vector <int> dp(n, 1);

        for(int i = 0; i < n; i++) {
            string s1 = words[i];
            int ln1 = s1.size();

            for(int j = i+1; j < n; j++) {
                string s2 = words[j];
                int ln2 = s2.size();

                if(ln1 > ln2+1) break;

                if(ln1 != ln2+1) continue;

                int x = 0, y = 0, c = 0;
                while(x < ln1 and y < ln2) {
                    if(s1[x] == s2[y]) x++, y++;
                    else {
                        x++, c++;
                        if(c > 1) break;
                    }
                }

                if(y != ln2 or c > 1) continue;

                dp[j] = max(dp[j], dp[i]+1);
                ans = max(ans, dp[j]);
            }
        }

        return ans;
    }
};
