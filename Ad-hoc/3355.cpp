#include <bits/stdc++.h>
using namespace std;

int pl[1123][1123], pc[1123][1123], p1[2123][2123], p2[2123][2123];
char grid[1123][1123];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, ans = -1, counter, m1, m2, a1, a2;
    cin >> n;
    for(int i = 0; i < n; i++) {
        pl[i][0] = pc[0][i] = 0;
    }
    for(int i = 0; i < 2 * n; i++) {
        p1[0][i] = p2[0][i] = 0;
    }
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cin >> grid[i][j];
            a1 = (j - i + n - 1 < n ? j : i);
            a2 = (j + i < n ? i : n - 1 - j);
            if(grid[i][j] == 'P') {
                pl[i][j + 1] = pl[i][j] + 1;
                pc[i + 1][j] = pc[i][j] + 1;
                p1[j - i + n - 1][a1 + 1] = p1[j - i + n - 1][a1] + 1;
                p2[j + i][a2 + 1] = p2[j + i][a2] + 1;
            } else {
                pl[i][j + 1] = pl[i][j];
                pc[i + 1][j] = pc[i][j];
                p1[j - i + n - 1][a1 + 1] = p1[j - i + n - 1][a1];
                p2[j + i][a2 + 1] = p2[j + i][a2];
            }
        }
    }
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            counter = 0;
            m1 = (j - i + n - 1 < n ? (j - i + n - 1) + 1 : (2 * n) - 1 - (j - i + n - 1)); 
            a1 = (j - i + n - 1 < n ? j : i);
            m2 = (j + i < n ? i + j + 1 : (2 * n) - 1 - (j + i));
            a2 = (j + i < n ? i : n - 1 - j);
            if(grid[i][j] == '.') {
                if(pl[i][n] > pl[i][j + 1]) counter++;
                if(pl[i][j]) counter++;
                if(pc[n][j] > pc[i + 1][j]) counter++;
                if(pc[i][j]) counter++;
                if(p1[j - i + n - 1][m1] > p1[j - i + n - 1][a1 + 1]) counter++;
                if(p1[j - i + n - 1][a1]) counter++;
                if(p2[j + i][m2] > p2[j + i][a2 + 1]) counter++;
                if(p2[j + i][a2]) counter++;
            }
            ans = max(ans, counter);
        }
    }
    cout << ans << "\n";
    return 0;
}
