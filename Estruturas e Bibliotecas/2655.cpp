#include <bits/stdc++.h>
using namespace std;

#define MAX 112345
typedef long long ll;

int n, m, bit[51][MAX], monsters[MAX];

int getbit(int i, int j) {
    int ans = 0;
    while(i) {
        ans += bit[j][i];
        i -= i & -i;
    }
    return ans;
}

void setbit(int i, int j, int delta) {
    while(i <= n) {
        bit[j][i] += delta;
        i += i & -i;
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int q, x, a, b;
    ll ans;
    memset(bit, 0, sizeof(bit));
    cin >> n >> q >> m;
    for(int i = 1; i <= n; i++) {
        cin >> x;
        monsters[i] = x;
        setbit(i, x - 1, 1);
    }
    while(q--) {
        cin >> x >> a >> b;
        if(x == 1) {
            ans = 0;
            for(int i = 0; i < m; i++) {
                ans += (getbit(b, i) - getbit(a - 1, i)) > 0;
            }
            cout << ans << "\n";
        } else {
            setbit(a, monsters[a] - 1, -1);
            setbit(a, b - 1, 1);
            monsters[a] = b;
        }
    }
    return 0;
}
