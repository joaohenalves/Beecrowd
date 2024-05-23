#include <bits/stdc++.h>
using namespace std;


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    while(cin >> n, n) {
        cout << (n * (n + 1) * (2 * n + 1)) / 6 << "\n";
    }
    return 0;
}
