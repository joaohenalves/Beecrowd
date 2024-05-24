#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 11234;
const int MAX_M = 1123;

int t[4], memo[4][11234], q[4][1123], w[4][1123];

int dp(int type, int weight) {
    if(type == 4) return 0; 
    if(memo[type][weight] != -1) return memo[type][weight];
    int ans = 0;
    for(int k = 0; k < t[type]; k++) {
        if(w[type][k] <= weight) {
            ans = max(ans, q[type][k] + dp(type + 1, weight - w[type][k]));
        }
    }
    ans = max(ans, dp(type + 1, weight));
    return memo[type][weight] = ans;
}


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    double aux;
    cin >> t[0] >> t[1] >> t[2] >> t[3] >> aux;
    int maxWeight = aux * 10;
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < t[i]; j++) {
            cin >> aux;
            q[i][j] = aux * 10;
        }
        for (int j = 0; j < t[i]; j++) {
            cin >> aux;
            w[i][j] = aux * 10;
        }
    }
    memset(memo, -1, sizeof(memo));
    cout << fixed << setprecision(1) << (double) dp(0, maxWeight) / 10.0 << "\n";
    return 0;
}
