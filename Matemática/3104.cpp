#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    string s;
    ll a = 0, b;
    cin >> s;
    cin >> b;
    for(int i = 0; i < s.size(); i++) {
        a *= 10;
        a += s[i] - '0';
        a %= b;
    }
    cout << a << "\n";
    return 0;
}
