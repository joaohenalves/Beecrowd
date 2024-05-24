#include <bits/stdc++.h>
using namespace std;

int n, m, de = 30, rp = 60, is = 150, dp[112][112], s1[112], s2[112];

int editDistance() {
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            if(s1[i - 1] == s2[j - 1]) dp[i][j] = dp[i - 1][j - 1];
            else dp[i][j] = min(dp[i - 1][j - 1] + rp, min(dp[i][j - 1] + de, dp[i - 1][j] + is));
        }
    }
    return dp[n][m];
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t, id;
    double r, ans;
    string s;
    for(int i = 0; i <= 100; i++) {
        dp[0][i] = i * de;
        dp[i][0] = i * is;
    }
    cin >> t;
    for(int i = 1; i <= t; i++) {
        unordered_map<string, int> words;
        id = 0;
        cin >> r >> m;
        for(int j = 0; j < m; j++) {
            cin >> s;
            if(words[s] == 0) words[s] = ++id;
            s2[j] = words[s];
        }
        cin >> n;
        for(int j = 0; j < n; j++) {
            cin >> s;
            if(words[s] == 0) words[s] = ++id;
            s1[j] = words[s];
        }
        cout << "Caso #" << i << ": R$ ";
        ans = (double) editDistance() / 60.0 * r;
        s = to_string(ans);
        s.erase(s.length() - 4);
        s[s.size() - 3] = ',';
        cout << s << "\n";
    }
    return 0;
}
