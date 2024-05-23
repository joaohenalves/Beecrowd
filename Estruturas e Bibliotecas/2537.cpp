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
        for(int j = y; j <= n; j += j & -j) {
            bit[i][j] += delta;
        }
    }
}
 
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int x, x1, y1, x2, y2;
    while(cin >> n >> m) {
        for(int i = 0; i <= n; i++) {
            for(int j = 0; j <= n; j++) {
                bit[i][j] = 0;
            }
        }
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= n; j++) {
                cin >> x;
                if(x) setbit(i, j, 1);
            }
        }
        for(int i = 0; i < m; i++) {
            cin >> x1 >> y1;
            setbit(x1, y1, 1);
            cin >> x1 >> y1 >> x2 >> y2;
            cout << getbit(x2, y2) - getbit(x2, y1 - 1) - getbit(x1 - 1, y2) + getbit(x1 - 1, y1 - 1) << "\n";
        }
    }
    return 0;
}
