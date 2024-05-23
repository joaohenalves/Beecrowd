#include <bits/stdc++.h>
using namespace std;

#define MAX 1123456
typedef long long ll;

int n, m, bit[2][MAX], l[MAX];

int getbit(int i, int op) {
    int ans = 0;
    while(i) {
        ans += bit[op][i];
        i -= i & -i;
    }
    return ans;
}

void setbit(int i, int op, int delta) {
    while(i <= n) {
        bit[op][i] += delta;
        i += i & -i;
    }
}
 
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int x, res;
    ll ans;
    while(cin >> n) {
        ans = 0;
        for(int i = 0; i <= n; i++) bit[0][i] = bit[1][i] = 0;
        for(int i = 1; i <= n; i++) {
            cin >> l[i];
            setbit(l[i], 0, 1);
        }
        for(int i = 1; i <= n; i++) {
            ans +=  (ll) (getbit(n, 1) - getbit(l[i], 1)) * (ll) getbit(l[i] - 1, 0);
            setbit(l[i], 1, 1);
            setbit(l[i], 0, -1);
        }
        cout << ans << "\n";
    }
    return 0;
}
