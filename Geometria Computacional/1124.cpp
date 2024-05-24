#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int l, c, r1, r2, lado1, lado2;
    while(cin >> l >> c >> r1 >> r2, l) {
        if(r2 > r1) swap(r1, r2);
        if(r1 * 2 > l || r1 * 2 > c) {
            cout << "N\n";
            continue;
        }
        lado1 = c - r1 - r2;
        lado2 = l - r1 - r2;
        if(sqrt(lado1 * lado1 + lado2 * lado2) >= r1 + r2) cout << 'S';
        else cout << 'N';
        cout << "\n";
    }
    return 0;
}
