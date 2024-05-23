#include <bits/stdc++.h>
using namespace std;

#define MAX 10001
#define MOD 100000007
typedef long long ll;


ll extended_gcd(ll a, ll b, ll &x, ll &y) {
    if (b == 0) {
        x = 1;
        y = 0;
        return a;
    }
    ll x1, y1;
    ll d = extended_gcd(b, a % b, x1, y1);
    x = y1;
    y = x1 - y1 * (a / b);
    return d;
}

ll modInverse(ll a, ll m) {
    ll x, y;
    ll g = extended_gcd(a, m, x, y);
    if (g != 1) {
        // a and m aren't relatively prime, so modular inverse doesn't exist
        return -1;
    } else {
        return (x % m + m) % m; // Ensure it's non-negative
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    string s;
    ll a, b, fact[MAX];
    int freq[26];
    fact[0] = 1;
    for(int i = 1; i < MAX; i++) fact[i] = (fact[i - 1] * i) % MOD;
    while(getline(cin, s), s[0] != '0') {
        memset(freq, 0, sizeof(freq));
        for(int i = 0; i < s.size(); i++) freq[s[i] - 'a']++;
        a = fact[s.size()]; b = 1;
        for(int i = 0; i < 26; i++) {b *= fact[freq[i]]; b %= MOD;}
        b = modInverse(b, MOD);
        cout << (a * b) % MOD << "\n";
    }
    return 0;
}
