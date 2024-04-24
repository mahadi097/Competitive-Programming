#include <iostream>
#include <stdio.h>
#include <cmath>
#include <algorithm>
using namespace std;

int main() {
    int t;
    int sides[3];
    cin >> t;

    for (int i = 1; i <= t; i++) {
        for (int j = 0; j < 3; j++) {
            cin >> sides[j];
        }
        sort(sides, sides+3);

        if ( ( (sides[0] * sides[0]) + sides[1] * sides[1] ) == (sides[2] * sides[2]) ) {
            printf("Case %d: yes\n", i);
        }
        else {
            printf("Case %d: no\n", i);
        }
    }

    return 0;
}
