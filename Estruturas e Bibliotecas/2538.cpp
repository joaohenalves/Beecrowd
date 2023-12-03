#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define MAX 100001

int bit[MAX];

void setbit(int i, int delta) {
    while(i <= MAX) {
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
    int ip, m, pc, na, res, ans;
    while(cin >> ip >> m) {
        memset(bit, 0, sizeof(bit));
        ans = 0;
        while(m--) {
            cin >> pc >> na;
            res = getbit(min(pc + ip, MAX)) - getbit(max(0, pc - ip - 1));
            if(res <= na) {
                setbit(pc, 1);
                ans++;
            }
        }
        cout << ans << "\n";
    }
    return 0;
}
