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
#define pii             pair <ll, paired>
#define SIZE            505
#define INF             1000000005

ll dr4[] = {0, 1, -1, 0, 0};
ll dc4[] = {0, 0, 0, 1, -1};

vector <paired> adj_list[SIZE];
ll node;
ll dis[SIZE];
map <ll, ll> m;
vector <ll> st, v;

void clear_data();
ll dijkstra(ll n);

int main() {
    ll t, n, a, b, x, y, z, i, j, k, f, ans;
    scand(t);

    while(t--) {
        clear_data();

        scand(f), scand(node);
        string s;

        while(f--) {
            scand(x);

            m[x] = 1;
            dis[x] = 0;
            st.pb(x);
        }

        ll n1, n2, w;

        cin.ignore();
        while(getline(cin, s)) {
            if(s.empty()) {
                break;
            }
            stringstream ss(s);

            ss >> n1 >> n2 >> w;

            adj_list[n1].pb(mp(n2, w));
            adj_list[n2].pb(mp(n1, w));
        }

        ans = INF;
        ll in;

        for1(i, node) {
            if(!m[i]) {
                a = dijkstra(i);
//                cout << i << " " << a << endl;

                if(ans > a) {
                    ans = a;
                    in = i;
                }

                for1(j, node) {
                    if(!m[j]) {
                        dis[j] = INF;
                    }
                }
            }
        }
        if(st.size() == node) {
            in = 1;
        }
        printd(in);
//        v.pb(in);
//        printd(ans);

        if(t) {
            newline;
        }
    }

//    for0(i, v.size()) {
//        printd(v[i]);
//        if(i < v.size()-1) {
//            newline;
//        }
//    }

    return 0;
}

void clear_data() {
    ll i;
    m.clear();
    st.clear();
    for0(i, SIZE) {
        adj_list[i].clear();
        dis[i] = INF;
    }
}

ll dijkstra(ll n) {
    priority_queue <paired, vector<paired>, greater<paired> > pq;

    ll x = dis[n];
    ll u, v, i, w;

    dis[n] = 0;
    pq.push(mp(0, n));

    for0(i, st.size()) {
        pq.push(mp(0, st[i]));
    }

    while(!pq.empty()) {
        u = pq.top().second;
        pq.pop();

        for0(i, adj_list[u].size()) {
            v = adj_list[u][i].first;
            w = adj_list[u][i].second;

            if(dis[v] > (dis[u] + w)) {
                dis[v] = dis[u] + w;
//                cout << u << " " << v << " " << dis[u] << " " << dis[v] << " " << w << endl;
                pq.push(mp(dis[v], v));
            }
        }

    }

    ll maxi = 0;
    for1(i, node) {
        maxi = max(maxi, dis[i]);
//        cout << i << " " << dis[i] << endl;
    }
//    newline;
    dis[n] = x;

    return maxi;
}

//1
//3 7
//1 6 6
//1 2 8
//2 5 11
//1 4 7
//4 5 12
//6 5 15
//1 3 10
//3 4 5
//4 7 20
//7 5 13
