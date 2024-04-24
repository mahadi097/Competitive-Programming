#include <iostream>
#include <stdio.h>
#include <cstring>
using namespace std;

int main() {
    char str[100];

    gets(str);

    int length = strlen(str);
    int count = 0;

    for (int i = 0; i < length; i++) {
        if ( str[i] == 'D' ) {
            if ( str[i+1] == 'a' && str[i+2] == 'n' && str[i+3] == 'i' && str[i+4] == 'l' ) {
                count++;
            }
        }
        if ( str[i] == 'O' ) {
            if ( str[i+1] == 'l' && str[i+2] == 'y' && str[i+3] == 'a' ) {
                count++;
            }
        }
        if ( str[i] == 'S' ) {
            if ( str[i+1] == 'l' && str[i+2] == 'a' && str[i+3] == 'v' && str[i+4] == 'a' ) {
                count++;
            }
        }
        if ( str[i] == 'A' ) {
            if ( str[i+1] == 'n' && str[i+2] == 'n' ) {
                count++;
            }
        }
        if ( str[i] == 'N' ) {
            if ( str[i+1] == 'i' && str[i+2] == 'k' && str[i+3] == 'i' && str[i+4] == 't' && str[i+5] == 'a' ) {
                count++;
            }
        }
    }

    if (count == 1) {
         printf("YES\n");
    }
    else {
        printf("NO\n");
    }

    return 0;
}
