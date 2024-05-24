#include <bits/stdc++.h>
using namespace std;

constexpr int INF = INT_MAX;

int n, m, cost, c[2134], v[2123], memo[2123][2123], sol[2123][2123];

int dp(int y, int a) {
    int op1, op2;
    if(y == n + 1) return 0;
    if(memo[y][a] != -1) return memo[y][a];
    op1 = c[0] + cost - v[a] + dp(y + 1, 1);
    op2 = (a < m ? c[a] + dp(y + 1, a + 1) : INF);
    sol[y][a] = (op1 <= op2 ? 1 : a + 1);
    return memo[y][a] = min(op1, op2);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int start, i, t, age, first;
    while(cin >> n >> start >> m >> cost) {
        for(i = 0; i < m; i++) cin >> c[i];
        for(i = 1; i <= m; i++) cin >> v[i];
        for(i = 0; i <= n; i++)
            memset(memo[i], -1, (m + 1) * sizeof(memo[0][0]));
        cout << dp(1, start) << "\n";
        t = 1; age = start; first = 1;
        do {
            if(sol[t][age] == 1) {
                if(first) first = 0;
                else cout << " ";
                cout << t;
            }
            age = sol[t][age]; t++;
        } while (t <= n);
        cout << (first ? "0" : "") << "\n";
    }
    return 0;
}
