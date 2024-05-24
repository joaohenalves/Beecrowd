#include <bits/stdc++.h>
using namespace std;

int a[51234];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, c, m, t, counter, trips, mx;
    cin >> t;
    while(t--) {
        cin >> n >> c >> m;
        counter = trips = mx = 0;
        for(int i = 0; i < m; i++) {
            cin >> a[i];
        }
        sort(a, a + m);
        for(int i = m - 1; i >= 0; i--) {
            if(counter < c) {
                counter++;
                mx = max(mx, a[i]);
            } else {
                trips += mx * 2;
                mx = a[i];
                counter = 1;
            }
        }
        if(counter) trips += mx * 2;
        cout << trips << "\n";
    }

    return 0;
}
