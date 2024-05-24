#include <bits/stdc++.h>
using namespace std;

bool isPrime[1123];
int n;

void sieve() {
    memset(isPrime, 1, sizeof(isPrime));
    for(int i = 2; i * i <= n; i++) {
        if(isPrime[i]) {
            for(int j = i * i; j <= n; j += i) {
                isPrime[j] = 0;
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    sieve();
    for(int i = n; i >= 2; i--) {
        if(isPrime[i] && isPrime[i - 2]) {
            cout << i - 2 << " " << i << "\n";
            break;
        }
    }
    return 0;
}
