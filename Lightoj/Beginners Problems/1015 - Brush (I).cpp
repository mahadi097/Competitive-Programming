#include <iostream>
#include <stdio.h>
using namespace std;

int main() {
    int t, i, j;
    int a[1000], n, sum;

    scanf("%d", &t);

    for (i = 1; i <= t; i++) {
        scanf("%d", &n);
        sum = 0;
        for (j = 0; j < n; j++) {
            scanf("%d", &a[i]);
            if (a[i] > 0) {
                sum += a[i];
            }
        }
        printf("Case %d: %d\n", i, sum);
    }

    return 0;
}
