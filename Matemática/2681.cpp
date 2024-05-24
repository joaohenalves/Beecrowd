#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll expbin(ll a, ll b) {
    if(b == 0) return 1;
    if(b & 1) return (a * expbin(a, b - 1)) % 86400;
    ll c = expbin(a, b >> 1);
    return (c * c) % 86400;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    string str;
    int ans, m, s;
    ll n = 0;
    cin >> str;
    for(int i = 0; i < str.size(); i++) {
        n *= 10;
        n += str[i] - '0';
        n %= 86400;
    }
    ans = expbin(2, n) - 1;
    s = ans % 60;
    ans /= 60;
    m = ans % 60;
    ans /= 60;
    printf("%02d:%02d:%02d\n", ans, m, s);
    return 0;
}
