#include <bits/stdc++.h>
using namespace std;

int memo[5123][5123];
 
int lcs(const string &s1, const string &s2) {
    for (int i = 1; i <= s1.size(); i++) {
        for (int j = 1; j <= s2.size(); j++) {
            if (s1[i - 1] == s2[j - 1]) {
                memo[i][j] = memo[i - 1][j - 1] + 1;
            } else {
                memo[i][j] = max(memo[i - 1][j], memo[i][j - 1]);
            }
        }
    }
    return memo[s1.size()][s2.size()];
}
 
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    string s1, s2;
    cin >> s1 >> s2;
    cout << lcs(s1, s2) << "\n";
    return 0;
}
