#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, i;
    scanf("%d", &n);

    vector <long long int> vec(n);

    for (i = 0; i < n; i++) {
        scanf("%lld", &vec[i]);
    }

    sort(vec.begin(), vec.end());

    for (i = 0; i < vec.size(); i++) {
        if (i == vec.size()-1) {
            cout << vec[i];
        }
        else {
            cout << vec[i] << " ";
        }
    }
    cout << endl;

    return 0;
}

