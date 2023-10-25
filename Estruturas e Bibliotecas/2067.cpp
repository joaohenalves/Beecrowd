#include <bits/stdc++.h>
using namespace std;


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int grid[212][212];
    int exists[212];
    int si[] = {-1, -1, 0};
    int sj[] = {-1, 0, -1};
    memset(exists, 0, sizeof(exists));
    int n, m, temp, i, j, k, ii, jj, minDist, q;
    cin >> n >> m;
    for(i = 0; i < n; i++) {
        for(j = 0; j < m; j++) {
            cin >> temp;
            grid[i][j] = temp ? 1 : 0;
        }
    }
    for(i = 0; i < n; i++) {
        for(j = 0; j < m; j++) {
            if(grid[i][j] == 1) {
                minDist = 999;
                for(k = 0; k < 3; k++) {
                    ii = i + si[k];
                    jj = j + sj[k];
                    if(ii >= 0 && jj >= 0)
                        minDist = min(min(minDist, grid[ii][jj]), min(i, j));
                }
                grid[i][j] = minDist + 1;
                exists[minDist + 1] = 1;
            }
        }
    }
    cin >> q;
    for(i = 0; i < q; i++) {
        cin >> temp;
        cout << (exists[temp] ? "yes" : "no") << "\n"; 
    }
    return 0;
}
