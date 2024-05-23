#include <bits/stdc++.h>
using namespace std;


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    double a, b, c, ans;
    cin >> a >> b >> c;
    if(a * a != b * b + c * c) {
        cout << "Nao eh retangulo!\n";
    } else {
        ans = b * c / 2;
        ans += 3 * ((c / 2) * (c / 2)) / 2;
        cout << "AREA = " << (int) ans << "\n";
    }
    return 0;
}
