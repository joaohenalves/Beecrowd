#include <bits/stdc++.h>
using namespace std;

constexpr long long MOD = 1e9 + 7;

int v[1123456];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, k;
    long long ans;
    while(cin >> n >> k) {
        ans = 0;
        for(int i = 0; i < n; i++) {
            cin >> v[i];
        }
        sort(v, v + n);
        for(int i = n - 1; i >= n - k; i--) {
            ans += v[i];
            ans %= MOD;
        }
        cout << ans << "\n";
    }
    return 0;
}
