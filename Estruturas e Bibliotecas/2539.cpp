#include <bits/stdc++.h>
using namespace std;

#define MAX 112345
typedef long long ll;

int n, bit[MAX], l[MAX];

void setbit(int i, int delta) {
    while(i <= n) {
        bit[i] += delta;
        i += i & -i;
    }
}

int getbit(int i) {
    int ans = 0;
    while(i) {
        ans += bit[i];
        i -= i & -i;
    }
    return ans;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll ans;
    while(cin >> n) {
        for(int i = 0; i < n; i++) {
            cin >> l[i];
            bit[i + 1] = 0;
        }
        bit[0] = ans = 0;
        for(int i = n - 1; i >= 0; i--) {
            ans += getbit(n) - getbit(l[i]);
            setbit(l[i], 1);
        }
        cout << ans << "\n";
    }
}
