#include <bits/stdc++.h>
using namespace std;

#define MAX 51234

int idx, l[MAX];
bool isPrime[MAX];

void sieve() {
    memset(isPrime, 1, sizeof(isPrime));
    for(int i = 2; i * i < MAX; i++) {
        if(isPrime[i]) {
            for(int j = i * i; j <= MAX; j += i) {
                isPrime[j] = 0;
            }
        }
    }
    idx = 0;
    for(int i = 2; i < MAX; i++) {
        if(isPrime[i]) l[idx++] = i;
    }
}

int phiFact(int n) {
    int exp, ans = 1;
    for(int i = 0; i < idx; i++) {
        if(l[i] * l[i] > n) break;
        exp = 0;
        while(n % l[i] == 0) {
            n /= l[i];
            exp++;
        }
        if(exp) {
            ans *= (l[i] - 1) * pow(l[i], exp - 1);
        }
    }
    if(n > 1) ans *= (n - 1);
    return ans;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    sieve();
    while(cin >> n) {
        cout << phiFact(n) / 2 << "\n";
    }
    return 0;
}
