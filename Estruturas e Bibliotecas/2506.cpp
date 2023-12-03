#include <bits/stdc++.h>
using namespace std;


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, h, m, c, t, current, ans;
    while(cin >> n) {
        current = 0;
        ans = 0;
        for(int i = 0; i < n; i++) {
            cin >> h >> m >> c;
            t = (h - 7) * 60 + m;
            while(current < t) current += 30;
            if(current - t > c) ans++;
            current += 30;
        }
        cout << ans << "\n";
    }
    return 0;
}
