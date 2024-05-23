#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void ident(ll a[2][2]) {
    a[0][0] = a[1][1] = 1;
    a[0][1] = a[1][0] = 0;
}

void multMat(ll a[2][2], ll b[2][2], ll c[2][2], ll mod) {
    for(int i = 0; i < 2; i++) {
        for(int j = 0; j < 2; j++) {
            c[i][j] = (a[i][0] * b[0][j] + a[i][1] * b[1][j]) % mod;
        }
    }
}

ll findPeriod(ll m) {
    ll a = 0, b = 1, c;
    for(ll i = 0; i < m * m; i++) {
        c = (a + b) % m;
        a = b;
        b = c;
        if(a == 0 && b == 1) return i + 1;
    }
    return -1;
}

void expbin(ll a[2][2], ll b[2][2], ll n, ll mod) {
    ll c[2][2];
    if(n < 0) return;
    if(n == 0) ident(b);
    else if(n & 1) {
        expbin(a, c, n - 1, mod);
        multMat(a, c, b, mod);
    } else {
        expbin(a, c, n >> 1, mod);
        multMat(c, c, b, mod);
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll n, m, mod, a[2][2], b[2][2];
    a[0][0] = a[0][1] = a[1][0] = 1; a[1][1] = 0;
    while(cin >> n >> m) {
        mod = findPeriod(m);
        expbin(a, b, n, mod);
        expbin(a, b, b[0][1], m);
        cout << b[0][1] << "\n";
    }
    return 0;
}
