#include <iostream>
#include <stdio.h>
using namespace std;

long long int find_next_num(long long int num, long long int onroy_value);
long long int onroy_value_func(long long int num);

int main() {
    int i, t;
    long long int num, onroy_value, next_num;

    scanf("%d", &t);

    for (i = 1; i <= t; i++) {
        scanf("%lld", &num);

        onroy_value = onroy_value_func(num);
        next_num = find_next_num(num, onroy_value);

        printf("Case %d: %lld\n", i, next_num);
    }

    return 0;
}

long long int onroy_value_func(long long int num) {
    long long int onroy_value = 0;
    int div = 1, rem;

    while (num > 0) {
        div = num / 2;
        rem = num % 2;
        if (rem == 1) {
            onroy_value++;
        }
        num = div;
    }
    return onroy_value;
}

long long int find_next_num(long long int num, long long int onroy_value) {
    long long int next_num = num + 1;
    long long int onroy_value_next;

    while(1) {
        onroy_value_next = onroy_value_func(next_num);
        if (onroy_value == onroy_value_next) {
            return next_num;
        }
        else {
            next_num++;
        }
    }
}
