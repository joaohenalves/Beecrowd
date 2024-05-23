#include <bits/stdc++.h>
using namespace std;
 
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, a, b, t;
    while(cin >> n, n) {
        t = 0;
        for(int i = 0; i < n; i++) {
            cin >> a >> b;
            t += b / 2;
        }
        t /= 2;
        cout << t << "\n";
    }
    cout << "\n";
    return 0;
}
