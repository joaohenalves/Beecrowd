#include <bits/stdc++.h>
using namespace std;


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, c = 0;
    double l, q, last;
    cin >> n >> l >> q;
    vector<string> p(n);
    for(int i = 0; i < n; i++) {
        cin >> p[i];
    }
    while(l > 0) {
        last = l;
        c++;
        l -= q;
    }
    cout << fixed;
    cout.precision(1);
    cout << p[(c - 1) % n] << " " << last << "\n";
    return 0;
}
