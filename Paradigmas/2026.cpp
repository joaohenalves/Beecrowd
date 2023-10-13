#include <bits/stdc++.h>
using namespace std;

int knapsack(int v[], int w[], int W, int N) {
    int memo[N + 1][W + 1];
    for(int i = 0; i <= W; i++) memo[0][i] = 0;
    for(int j = 0; j <= N; j++) memo[j][0] = 0;

    for(int k = 1; k <= N; k++) {
        for(int l = 1; l <= W; l++) {
            if(w[k - 1] <= l) {
                memo[k][l] = max(v[k - 1] + memo[k - 1][l - w[k - 1]], memo[k - 1][l]);
            } else memo[k][l] = memo[k - 1][l];
        }
    }

    return memo[N][W];
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int v[100];
    int w[100];
    int c, N, W;
    cin >> c;
    for (int i = 0; i < c; i++) {
        cin >> N;
        cin >> W;
        for (int j = 0; j < N; j++) {
            cin >> v[j] >> w[j];
        }
        cout << "Galho " << i + 1 << ":\nNumero total de enfeites: " << knapsack(v, w, W, N) << "\n\n";
    }
    return 0;
}