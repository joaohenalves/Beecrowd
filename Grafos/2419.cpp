#include <bits/stdc++.h>
using namespace std;

int n, m, counter = 0;
int si[] = {-1, 1, 0, 0};
int sj[] = {0, 0, -1, 1};

void check(int i, int j, vector<string> &grid) {
    if(min(i, j) == 0 || j == m - 1 || i == n - 1) {
        counter++;
        return;
    } else {
        int ii, jj;
        for(int k = 0; k < 4; k++) {
            ii = i + si[k];
            jj = j + sj[k];
            if(grid[ii][jj] == '.') {
                counter++;
                return;
            }
        }
    }
}


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    vector<string> grid(n);
    for(int i = 0; i < n; i++) {
        cin >> grid[i];
    }
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(grid[i][j] == '#')
                check(i, j, grid);
        }
    }
    cout << counter << "\n";
    return 0;
}