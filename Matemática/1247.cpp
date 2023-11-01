#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    double d, vf, vg;
    while(cin >> d >> vf >> vg) {
        cout << ((sqrt(pow(d, 2) + pow(12, 2)) / vg <= 12 / vf) ? "S" : "N") << "\n";
    }
    return 0;
}
