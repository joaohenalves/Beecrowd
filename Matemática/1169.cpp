#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    string str;
    int n, m;
    long long res;
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> m;
        res = (pow(2, m) - 1) / 12 / 1000;
        cout << res << " kg\n";
    }
    return 0;
}