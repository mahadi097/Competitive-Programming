#include <bits/stdc++.h>
using namespace std;


//TEMPLATE
#define pb              push_back
#define mp              make_pair
#define ll              long long int
#define pi              3.1415926536
#define mod             1000000007
#define newline         printf("\n")
#define printminusone   printf("-1\n")
#define scand(n)        scanf("%lld", &n)
#define printd(n)       printf("%lld\n", n)
#define scandd(n)       scanf("%lf", &n)
#define printdd(n)      printf("%lf\n", n)
#define reversed(s)     reverse(s.begin(), s.end())
#define asorted(s)      sort(s.begin(), s.end())
#define dsorted(s)      sort(s.begin(), s.end(), descending_func)
#define for0(i, n)      for (i = 0; i < n; i++)
#define for1(i, n)      for (i = 1; i <= n; i++)
#define paired          pair <ll, ll>
#define SIZE            205

map <string, bool> visited;
map <string, ll> dis;
vector <string> word;
string st, en;

ll bfs();

int main() {
    ll t, n, i, j, k;
    string str, s1, s2, s;
    scand(t);

    for1(i, t) {
        word.clear();

        while((cin >> str) && str != "*") {
            word.pb(str);
        }

        cin.ignore();

        while(getline(cin, s) && s != "") {
            visited.clear();
            dis.clear();

            ll steps;

            stringstream ss(s);
            ss >> st >> en;

            if(st == en) {
                steps = 0;
            }
            else {
                steps = bfs();
            }

            cout << st << " " << en << " " << steps << "\n";
        }

        if(i != t) {
            newline;
        }
    }

    return 0;
}

ll bfs() {
    queue <string> q;

    q.push(st);
    visited[st] = 1;
    dis[st] = 0;

    string s;
    ll i, j, k;

    while(!q.empty()) {
        s = q.front();
        q.pop();

        for0(i, word.size()) {
            if(s.size() == word[i].size() && !visited[word[i]]) {
                ll diff = 0;

                for0(j, s.size()) {
                    if(s[j] != word[i][j]) {
                        diff++;
                    }
                    if(diff > 1) {
                        break;
                    }
                }

                if(diff == 1) {
                    dis[word[i]] = dis[s] + 1;
                    visited[word[i]] = 1;
                    q.push(word[i]);

                    if(word[i] == en) {
                        return dis[word[i]];
                    }
                }
            }
        }
    }
}
