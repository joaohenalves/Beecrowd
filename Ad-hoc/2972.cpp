#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
 
int main() {
    ll n, c = 0;
    cin >> n;
    while(n) {
        c += (n & 1);
        n >>= 1;
    }
    cout << (1ll << c) << "\n";
    return 0;
}
