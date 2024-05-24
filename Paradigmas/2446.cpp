#include <bits/stdc++.h>
using namespace std;

int knapsack(int v[], int W, int N) {
    int memo[W + 1];
    memset(memo, 0, sizeof(memo));

    for(int k = 1; k <= N; k++) {
        for(int l = W; l >= v[k - 1]; l--) {
            memo[l] = max(v[k - 1] + memo[l - v[k - 1]], memo[l]);
            if(memo[l] == W) return W;
        }
    }

    return memo[W];
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int v[1000];
    int N, W;
    cin >> W >> N;
    for (int i = 0; i < N; i++) {
        cin >> v[i];
    }
    cout << (knapsack(v, W, N) == W ? "S\n" : "N\n");
    return 0;
}
