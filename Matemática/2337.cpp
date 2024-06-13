#include <bits/stdc++.h>
using namespace std;

#define MAX 45
typedef long long ll;

ll f[MAX];

ll gcd(ll a , ll b) {
    if(b == 0) return a;
    return gcd(b, a % b);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    ll a, b, m;
    f[0] = 0;
    f[1] = 1;
    for(int i = 2; i < MAX; i++) {
        f[i] = f[i - 1] + f[i - 2];
    }
    while(cin >> n) {
        a = f[n + 2];
        b = 1LL << n;
        m = gcd(a, b);
        cout << a / m << '/' << b / m << "\n";
    }
    return 0;
}
