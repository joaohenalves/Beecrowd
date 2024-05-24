#include <bits/stdc++.h>
using namespace std;

int memo[112][60][60][60];
int songs[112];
int n, k;

int dp(int i, int c1, int c2, int c3) {
    int ch1, ch2 = 0, ch3 = 0, ch4 = 0;
    if(i == n) return 0;
    if(memo[i][c1][c2][c3] != -1) return memo[i][c1][c2][c3];
    ch1 = dp(i + 1, c1, c2, c3);
    if(songs[i] <= c1) ch2 = dp(i + 1, c1 - songs[i], c2, c3) + songs[i];
    if(songs[i] <= c2) ch3 = dp(i + 1, c1, c2 - songs[i], c3) + songs[i];
    if(songs[i] <= c3) ch4 = dp(i + 1, c1, c2, c3 - songs[i]) + songs[i];
    return memo[i][c1][c2][c3] = max(ch1, max(ch2, max(ch3, ch4)));
}


 
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    memset(memo, -1, sizeof(memo));
    cin >> n >> k;
    vector<int> cap(3);
    for(int i = 0; i < n; i++) {
        cin >> songs[i];
    }
    for(int j = 0; j < k; j++) {
        cin >> cap[j];
    }
    cout << dp(0, cap[0], cap[1], cap[2]) << "\n";
    return 0;
}
