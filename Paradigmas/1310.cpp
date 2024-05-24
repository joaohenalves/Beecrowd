#include <bits/stdc++.h>
using namespace std;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, m, c, days[51];
    while(cin >> n >> c) {
        days[0] = m = 0;
        for(int i = 1; i <= n; i++) {
            cin >> days[i];
            days[i] -= c;
        }
        for(int i = 1; i <= n; i++) {
            days[i] = max(days[i - 1] + days[i], days[i]);
            m = max(days[i], m);
        }
        cout << m << "\n";
    }
    return 0;
}
