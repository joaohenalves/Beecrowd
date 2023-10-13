#include <bits/stdc++.h>
using namespace std;

#define MAX 112345
typedef long long ll;

int n;
vector<int> bit(MAX);

void setbit(int i, int delta) {
    while(i <= n) {
        bit[i] += delta;
        i += i & -i;
    }
}

ll getbit(int i) {
    ll ans = 0;
    while(i) {
        ans += bit[i];
        i -= i & -i;
    }
    return ans;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int x;
    ll ans = 0;
    cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> x;
        ans += (i - 1) - getbit(x - 1);
        setbit(x, 1);
    }
    cout << ans << "\n";
    return 0;
}