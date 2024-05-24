#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, m, a, b, c;
    cin >> n;
    while(n--) {
        cin >> m >> a >> b >> c;
        if(m) {
            cout << (a + b + c > 1 ? 'X' : '0') << "\n";
        } else {
            cout << (a + b + c <= 1 ? to_string(a + b + c) : "X") << "\n";
        }
    }
    return 0;
}
