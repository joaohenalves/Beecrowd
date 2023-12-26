#include <bits/stdc++.h>
using namespace std;

int v[1123], w[1123], memo[1123], W, N;

int knapsack() {
    memset(memo, 0, (W + 1) * sizeof(memo[0]));
    for(int k = 1; k <= N; k++) {
        for(int l = W; l >= w[k - 1]; l--) {
            memo[l] = max(v[k - 1] + memo[l - w[k - 1]], memo[l]);
        }
    }
    return memo[W];
}


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int cases = 1;
    while(cin >> N >> W, N) {
        for(int i = 0; i < N; i++) {
            cin >> w[i] >> v[i];
        }
        cout << "Caso " << cases++ << ": " << knapsack() << "\n";
    }
    return 0;
}
