#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    double a, b, l, result;
    while(cin >> n) {
        cin >> a >> b >> l;
        result = (sqrt(pow(a, 2) + pow(b, 2)) * n * l) / 10000;
        cout << fixed;
        cout.precision(4);
        cout << result << "\n";
    }
    return 0;
}
