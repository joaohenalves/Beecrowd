#include <bits/stdc++.h>
using namespace std;

int weight, sacks;

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
    int i1 = N, w1 = W;
    while (i1 > 0 && w1 > 0) {
        if (memo[i1][w1] != memo[i1 - 1][w1]) {
            weight += w[i1 - 1];
            w1 -= w[i1 - 1];
            sacks++;
        }
        i1 -= 1;
    }
    return memo[N][W];
}


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int v[100];
    int w[100];
    int c, N, W = 50;
    cin >> c;
    for(int i = 0; i < c; i++) {
        cin >> N;
        for (int i = 0; i < N; i++) {
            cin >> v[i] >> w[i];
        }
        weight = 0;
        sacks = 0;
        cout << knapsack(v, w, W, N) << " brinquedos\nPeso: " << weight << " kg\nsobra(m) " << N - sacks << " pacote(s)\n\n";
    }
    return 0;
}