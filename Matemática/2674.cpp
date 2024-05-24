#include <bits/stdc++.h>
using namespace std;

#define MAX 112345

bool isPrime[MAX];

void sieve() {
    memset(isPrime, 1, sizeof(isPrime));
    isPrime[1] = isPrime[0] = 0;
    for(int i = 2; i * i < MAX; i++) {
        if(isPrime[i]) {
            for(int j = i * i; j < MAX; j += i) {
                isPrime[j] = 0;
            }
        }
    }
}

int check(int n) {
    while(n) {
        if(isPrime[n % 10] == 0) return 0;
        n /= 10;
    }
    return 1;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    sieve();
    while(cin >> n) {
        if(isPrime[n]) {
            cout << (check(n) ? "Super" : "Primo") << "\n";
        } else cout << "Nada\n";
    }
    return 0;
}
