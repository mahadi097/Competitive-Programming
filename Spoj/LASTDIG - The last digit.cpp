#include <stdio.h>
#define ll              long long
main() {
    int a, x;
    ll t, b;
    scanf("%d", &t);
    while(t--) {
        scanf("%d %lld", &a, &b);
        x = a % 10;
        if(b == 0)
            printf("1\n");
        else
            if(x == 0 || x == 1 || x == 5 || x == 6)
                printf("%d\n",x);
            else
                if(b%4 == 0)
                    printf("%d\n",(x*x*x*x) % 10);
                else if(b%4 == 1)
                    printf("%d\n",x % 10);
                else if(b%4 == 2)
                    printf("%d\n",(x*x) % 10);
                else if(b%4 == 3)
                    printf("%d\n",(x*x*x) % 10);
    }
}
