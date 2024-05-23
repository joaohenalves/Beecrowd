#include <bits/stdc++.h>
using namespace std;

#define MAX 1001
#define MOD 1000000007
typedef long long ll;


ll fastBinExp(ll a, ll b) {
    if(b == 0) return 1;
    if(b & 1) return (a * fastBinExp(a, b - 1)) % MOD;
    ll c = fastBinExp(a, b >> 1);
    return (c * c) % MOD;
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
    while(getline(cin, s)) {
        memset(freq, 0, sizeof(freq));
        for(int i = 0; i < s.size(); i++) freq[s[i] - 'A']++;
        a = fact[s.size()]; b = 1;
        for(int i = 0; i < 26; i++) {b *= fact[freq[i]]; b %= MOD;}
        b = fastBinExp(b, MOD - 2);
        cout << (a * b) % MOD << "\n";
    }
    return 0;
}
