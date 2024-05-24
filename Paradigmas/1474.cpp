#include <bits/stdc++.h>
using namespace std;

#define MOD 1000000
typedef long long ll;

ll n, k, l;

void ident(ll a[2][2]) {
    a[0][0] = a[1][1] = 1;
    a[0][1] = a[1][0] = 0;   
}

void multmat(ll a[2][2], ll b[2][2], ll c[2][2]) {
    for(int i = 0; i < 2; i++) {
        for(int j = 0; j < 2; j++) {
            c[i][j] = (a[i][0] * b[0][j] + a[i][1] * b[1][j]) % MOD;
        }
    }
}

void expbin(ll a[2][2], ll n, ll b[2][2]) {
    ll c[2][2];
    if(n == 0) ident(b);
    else if(n & 1) {
        expbin(a, n - 1, c);
        multmat(a, c, b);
    } else {
        expbin(a, n >> 1, c);
        multmat(c, c, b);
    }
}
 
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    while(cin >> n >> k >> l) {
        n /= 5;
        ll a[2][2], b[2][2];
        a[0][0] = 0; a[0][1] = 1; a[1][0] = (l % MOD); a[1][1] = (k % MOD);
        expbin(a, n, b);
        cout << setw(6) << setfill('0') << b[1][1] << "\n";
    }
    return 0;
}
