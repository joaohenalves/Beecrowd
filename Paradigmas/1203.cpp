#include <bits/stdc++.h>
using namespace std;

int r, k, n, degree[112], num[112], dp[5123];

int checkSum() {
    memset(dp, 0, sizeof(dp));
    dp[0] = 1;
    for(int i = 0; i < n; i++) {
        for(int j = k; j >= num[i]; j--) {
            dp[j] = dp[j] || dp[j - num[i]];
        }
    }
    return dp[k];
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int u, v, i, j;
    while(cin >> r >> k) {
        memset(degree, 0, sizeof(degree));
        for(i = 0; i < k; i++) {
            cin >> u >> v;
            degree[u]++;
            degree[v]++;
        }
        n = 0;
        for(j = 0; j <= r; j++) {
            if(degree[j]) num[n++] = degree[j];
        }
        cout << (checkSum() ? "S" : "N") << "\n";
    }
    return 0;
}
