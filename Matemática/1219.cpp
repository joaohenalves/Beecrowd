#include <bits/stdc++.h>
using namespace std;

#define PI acos(-1.)

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    double a, b, c, r, s, circR, tri, circA;
    while(cin >> a >> b >> c) {
        s = (a + b + c) / 2;
        tri = sqrt(s * (s - a) * (s - b) * (s - c));
        r = tri / s;
        circR = r * r * PI;
        r = a * b * c / (4 * tri);
        circA = r * r * PI;
        cout << fixed;
        cout.precision(4);
        cout << circA - tri << " " << tri - circR << " " << circR << "\n";
    }
    return 0;
}
