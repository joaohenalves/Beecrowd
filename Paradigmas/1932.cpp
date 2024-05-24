#include <bits/stdc++.h>
using namespace std;

int n, c, memo[212345][2], stocks[212345];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> c;
    for(int i = 1; i <= n; i++) {
        cin >> stocks[i];
    }
    memo[0][0] = stocks[0] = 0;
    memo[0][1] = INT_MIN;
    for(int i = 1; i <= n; i++) {
        memo[i][1] = max(memo[i - 1][1], memo[i - 1][0] - stocks[i] - c);
        memo[i][0] = max(memo[i - 1][0], memo[i - 1][1] + stocks[i]);
    }
    cout << memo[n][0] << "\n";
    return 0;
}
