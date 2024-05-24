#include <bits/stdc++.h>
using namespace std;

int k, rad[1000001], pos[1000001], memo[1000001];

int solve(int p) {
    if(p <= 0) return 0;
    if(memo[p] != -1) return memo[p];
    return memo[p] = max(solve(p - 1), rad[p] + solve(p - k));
}


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t, n, l, maxPos, limit;
    cin >> t;
    while(t--) {
        cin >> n >> k;
        maxPos = 0;
        for(int i = 0; i < n; i++) {
            cin >> pos[i];
            maxPos = max(maxPos, pos[i]);
        }
        memset(rad, 0, sizeof(rad));
        for(int j = 0; j < n; j++) {
            cin >> l;
            rad[pos[j]] = max(rad[pos[j]], l);
        }
        for(int i = 0; i <= maxPos; i++) memo[i] = -1;
        cout << solve(maxPos) << "\n";
    }
    return 0;
}
