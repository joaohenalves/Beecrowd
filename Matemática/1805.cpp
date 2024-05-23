#include <bits/stdc++.h>
using namespace std;

typedef long long ll;


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll a, b;
    cin >> a >> b;
    cout << (b * (b + 1) / 2) - (a * (a + 1) / 2) + a << "\n";
    return 0;
}
