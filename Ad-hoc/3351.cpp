#include <bits/stdc++.h>
using namespace std;

#define MAX 112345
typedef long long ll;

int n, t[MAX], nxt[MAX];
ll target;

bool check(ll x) {
    ll ans = 0;
    for(int i = 0; i < n && ans < target; i++) {
        if(t[i] <= x) {
            ans += 1 + (x - t[i]) / nxt[i];
        }
    }
    return ans >= target;
}

ll binSearch() {
    ll mid, inf = 0, sup = (1ll << 61);
    while(inf < sup) {
        mid = inf + ((sup - inf) / 2);
        if(!check(mid)) inf = mid + 1;
        else sup = mid;
    }
    return inf;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> target;
    for(int i = 0; i < n; i++) {
        cin >> t[i] >> nxt[i];
    }
    cout << binSearch() << "\n";
    return 0;
}
