#include <iostream>
#include <stdio.h>
#include <math.h>
using namespace std;

int main() {
    int i, t;
    int n, b;
    long long int num_of_digits;
    double arr[1000010];
    arr[0] = 0.0;

    for (i = 1; i <= pow(10,6); i++) {
        arr[i] = arr[i-1] + log10(i);
    }

    scanf("%d", &t);
    for (i = 1; i <= t; i++) {
        scanf("%d %d", &n, &b);
        num_of_digits = arr[n] / log10(b) + 1;
        printf("Case %d: %lld\n", i, num_of_digits);
    }

    return 0;
}
