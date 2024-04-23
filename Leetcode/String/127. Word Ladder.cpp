class Solution {
public:
    int vis[5005], dis[5005];

    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        int n = beginWord.size();
        queue <int> q;

        q.push(-1);

        while(!q.empty()) {
            int pos = q.front();
            string s = pos == -1 ? beginWord : wordList[pos];
            q.pop();

            for(int i = 0; i < wordList.size(); i++) {
                if(vis[i] or wordList[i] == beginWord) continue;

                int c = 0;
                for(int j = 0; j < n; j++) c += (s[j] != wordList[i][j]);

                if(c == 1) {
                    vis[i] = 1;
                    dis[i] = (pos == -1) ? 2 : dis[pos] + 1;
                    q.push(i);

                    if(wordList[i] == endWord) return dis[i];
                }
            }
        }

        return 0;
    }
};
