#include <bits/stdc++.h>
using namespace std;


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    double n, l, d, ans = 0;
    cin >> n >> l >> d;
    d /= 1000;
    ans = n * d;
    ans = ceil(ans / l) * l;
    cout << (int) ans << "\n";
    return 0;
}
