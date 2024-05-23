#include <bits/stdc++.h>
using namespace std;
 
#define MAX 112

int r[6], p[6], dp[25][25];

int editDistance(string &s1, string &s2) {
    int n = s1.size(), m = s2.size();
    for(int i = 0; i < 22; i++) dp[0][i] = dp[i][0] = i;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            if(s1[i - 1] == s2[j - 1]) dp[i][j] = dp[i - 1][j - 1];
            else dp[i][j] = min(dp[i - 1][j - 1], min(dp[i][j - 1], dp[i - 1][j])) + 1;
        }
    }
    return dp[n][m];
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, x;
    string s1, s2;
    cin >> n;
    memset(p, 0, sizeof(p));
    for(int i = 0; i < n; i++) {
        cin >> s1;
        for(int j = 0; j < 5; j++) {
            cin >> s2;
            r[j] = editDistance(s1, s2);
        }
        x = 7832478;
        for(int j = 0; j < 5; j++) {
            x = min(x, r[j]);
        }
        for(int j = 0; j < 5; j++) {
            if(r[j] == x) p[j] += r[j] == 0 ? 10 : 5;
        }
    }
    x = 0;
    for(int j = 0; j < 5; j++) {
        x = max(x, p[j]);
    }
    cout << fixed;
    cout.precision(1);
    cout << (double) x / 10. << "\n";
    vector<int> vv;
    for(int j = 0; j < 5; j++) {
        if(p[j] == x) vv.push_back(j + 1);
    }
    for(int i = 0; i < vv.size() - 1; i++) {
        cout << vv[i] << " ";
    }
    cout << vv.back() << "\n";
    return 0;
}
