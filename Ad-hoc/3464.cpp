#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, m, r, x, y, r1, x1, x2, y1, y2, temp, t = 0;
    cin >> n >> m >> r;
    for(int i = 0; i < r; i++) {
        cin >> x >> y >> r1;
        x--; y--;
        x1 = max(0, x - r1);
        x2 = min(m - 1, x + r1);
        y1 = max(0, y - r1);
        y2 = min(n - 1, y + r1);
        temp = (x2 - x1 + 1) * (y2 - y1 + 1);
        t += temp;
    }
    cout << t / (n * m) << "\n";
    return 0;
}
