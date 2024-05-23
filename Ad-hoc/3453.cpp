#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll a, b, x, d, aux, l, ans = 0;
    cin >> a >> b;
    d = 2 * a + 1;
    x = d + b;
    l = 4 * a * a;
    while(x <= l) {
        aux = sqrt(x);
        if(aux * aux == x) ans = x;
        x += d;
    }
    if(ans == 0) {
        x = b - d;
        while(x >= 1) {
            aux = sqrt(x);
            if(aux * aux == x) {
                ans = x;
                break;
            }
            x -= d;
        }
    }
    cout << ans << "\n";
    return 0;
}
