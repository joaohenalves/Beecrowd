#include <bits/stdc++.h>
using namespace std;


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int N, W;
    int v[1001];
    int w[1001];
    int memo[2001];
    while(cin >> N >> W) {
        for(int i = 0; i < N; i++) {
            cin >> w[i] >> v[i];
        }
        memset(memo, 0, sizeof(memo));
        for(int j = 1; j <= W; j++) {
            for(int k = 0; k < N; k++) {
                if(w[k] <= j) {
                    memo[j] = max(memo[j], memo[j - w[k]] + v[k]);
                }
            }
        }
        cout << memo[W] << "\n";
    }
    return 0;
}
