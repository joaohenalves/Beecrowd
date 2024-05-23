#include <bits/stdc++.h>
using namespace std;

#define MAX 50000
#define MAX2 51234

int indx, primes[MAX2];
bool isPrime[MAX2];

void sieve() {
    memset(isPrime, 1, sizeof(isPrime));
    for(int i = 2; i * i <= MAX; i++) {
        if(isPrime[i]) {
            for(int j = i * i; j <= MAX; j += i) {
                isPrime[j] = 0;
            }
        }
    }
    indx = 0;
    for(int i = 2; i < MAX; i++) {
        if(isPrime[i]) {
            primes[indx++] = i;
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t, n, i, flag;
    sieve();
    cin >> t;
    while(t--) {
        cin >> n;
        flag = i = 0;
        while(primes[i] * primes[i] <= n) {
            if(n % primes[i] == 0) {
                flag = 1;
                break;
            }
            i++;
        }
        cout << (flag ? "Not " : "") << "Prime\n";
    }
    return 0;
}
