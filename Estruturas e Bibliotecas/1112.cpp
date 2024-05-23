#include <bits/stdc++.h>
using namespace std;

#define MAX 1123
typedef long long ll;

int n, m, bit[MAX][MAX];

int getbit(int x, int y) {
    int ans = 0;
    for(int i = x; i > 0; i -= i & -i) {
        for(int j = y; j > 0; j -= j & -j) {
            ans += bit[i][j];
        }
    }
    return ans;
}

void setbit(int x, int y, int delta) {
    for(int i = x; i <= n; i += i & -i) {
        for(int j = y; j <= m; j += j & -j) {
            bit[i][j] += delta;
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int q, p, x, y, s, x2, y2, ans;
    char c;
    while(cin >> m >> n >> p, n) {
        for(int i = 0; i <= n; i++) {
            for(int j = 0; j <= m; j++) {
                bit[i][j] = 0;
            }
        }
        cin >> q;
        while(q--) {
            cin >> c;
            if(c == 'A') {
                cin >> s >> y >> x;
                y++; x++;
                setbit(x, y, s);
            } else {
                cin >> y >> x >> y2 >> x2;
                x++; y++; x2++; y2++;
                if(y2 > y) swap(y2, y);
                if(x2 > x) swap(x2, x);
                ans = getbit(x, y) - getbit(x, y2 - 1) - getbit(x2 - 1, y) + getbit(x2 - 1, y2 - 1);
                cout << ans * p << "\n";
            }
        }
        cout << "\n";
    }
    return 0;
}
