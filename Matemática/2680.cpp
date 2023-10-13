#include <bits/stdc++.h>
using namespace std;

constexpr int primeTheorem = 12345 / log(12345);
int ans;
vector<int> primeList;

void sieveOfEratosthenes(int n) {
    vector<bool> notPrime(n + 1);
    int limit = sqrt(n);
    for (int i = 2; i <= limit; i++) {
        if (!notPrime[i]) {
            for (int j = i * i; j <= n; j += i) {
                notPrime[j] = true;
            }
        }
    }
    for (int i = 2; i <= n; i++) {
        if (!notPrime[i]) {
            primeList.push_back(i);
        }
    }
}

void fact(int n) {
    int z;
    for(int i = 0; i < primeList.size() && primeList[i] * primeList[i] <= n; i++) {
        if(n % primeList[i] == 0) {
            z = 0;
            while(n % primeList[i] == 0) { z++; n/= primeList[i]; }
            ans *= (pow(primeList[i], z + 1) - 1) / (primeList[i] - 1);
        }
    }
    if(n > 1) { ans *= (pow(n, 2) - 1) / (n - 1); }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int c, n;
    cin >> c;
    primeList.reserve(primeTheorem);
    sieveOfEratosthenes(10000); //sqrt of 10^8
    while(c--) {
        ans = 1;
        cin >> n;
        fact(n);
        cout << ans << "\n";
    }
    return 0;
}