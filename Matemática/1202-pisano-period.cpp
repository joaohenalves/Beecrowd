#include <stdio.h>
#include <string.h>

#define MOD 1000
#define CYCLE 1500

int memo[1512];
char str[11234];

void fib() {
    memo[0] = 0;
    memo[1] = 1;
    for(int i = 2; i <= CYCLE; i++) {
        memo[i] = memo[i - 1] + memo[i - 2];
        memo[i] %= MOD;
    }
}

int main() {
    int t, n;
    fib();
    scanf("%d", &t);
    while(t--) {
        scanf(" %s", str);
        n = 0;
        for(int i = 0; i < strlen(str); i++) {
            n *= 2;
            n += str[i] - '0';
            n %= CYCLE;
        }
        printf("%03d\n", memo[n]);
    }
    return 0;
}
