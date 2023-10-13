#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define MAX 112345

ll x, y;
int p[MAX], pi;

int sieve(int n) {
    if(n % 2 == 0) return 2;
    p[0] = 2; pi = 1;
    for(int i = 3;; i++) {
        int r = sqrt(i), prime = 1;
        for(int j = 0; j < pi && prime && p[j] <= r; j++) {
            prime &= i % p[j] != 0;
        }
        if(prime) {
            p[pi++] = i;
            if(n % i == 0) return i;
        }
    }
}

ll extEuclides(ll a, ll b) {
    if (b == 0) {
        x = 1;
        y = 0;
        return a;
    }
    ll x1;
    ll d = extEuclides(b, a % b);
    x1 = x;
    x = y;
    y = x1 - y * (a / b);
    return d;
}

ll fastBinExp(ll a, ll b, ll n) {
    if(b == 0) return 1;
    if(b & 1) return (a * fastBinExp(a, b - 1, n)) % n;
    ll c = fastBinExp(a, b / 2, n);
    return (c * c) % n;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll n, e, c, p, q, d, phi;
    cin >> n >> e >> c;
    p = sieve(n);
    q = n / p;
    phi = (p - 1) * (q - 1);
    extEuclides(e, phi);
    d = ((x % phi) + phi) % phi;
    cout << fastBinExp(c, d, n) << "\n";
    return 0;
}