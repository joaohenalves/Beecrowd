#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int b[25];
    int c, n, size;
    cin >> c;
    for(int i = 0; i < c; i++) {
        cin >> n >> size;
        vector<int> memo(size + 1, size + 1);
        for(int j = 0; j < n; j++) {
            cin >> b[j];
        }
        memo[0] = 0;
        for (int l = 0; l < n; l++) {
            for (int k = b[l]; k <= size; k++) {
                if (memo[k - b[l]] + 1 < memo[k]) {
                    memo[k] = memo[k - b[l]] + 1;
                }
            }
        }
        cout << memo[size] << "\n";
    }
    return 0;
}
