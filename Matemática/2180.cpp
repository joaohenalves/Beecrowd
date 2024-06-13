#include <bits/stdc++.h>
using namespace std;

#define MAX 112345

int idx, pList[MAX];
bool isPrime[MAX];

void sieve() {
    memset(isPrime, 1, sizeof(isPrime));
    for(int i = 2; i * i < MAX; i++) {
        if(isPrime[i]) {
            for(int j = i * i; j < MAX; j += i) {
                isPrime[j] = 0;
            }
        }
    }
    idx = 0;
    for(int i = 2; i < MAX; i++) {
        if(isPrime[i]) pList[idx++] = i;
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, total = 0;
    cin >> n;
    sieve();
    int i = lower_bound(pList, pList + idx, n) - pList;
    for(int j = 0; j < 10; j++) {
        total += pList[i + j];
    }
    cout << total << " km/h\n";
    cout << 60000000 / total << " h / " << 60000000 / total / 24 << " d\n";
    return 0;
}
