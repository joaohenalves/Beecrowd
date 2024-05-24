#include <bits/stdc++.h>
using namespace std;

#define MAX 1123

int n, m;
int ai[] = {-1, 1, 0, 0};
int aj[] = {0, 0, 1, -1};

vector<string> grid(MAX);

int solve() {
    int ii, jj, ans = 0;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(grid[i][j] == '#') {
                for(int k = 0; k < 4; k++) {
                    ii = i + ai[k];
                    jj = j + aj[k];
                    if(ii < 0 || ii >= n || jj < 0 || jj >= m || grid[ii][jj] == '.') {
                        ans++;
                        break;
                    }
                }
            }
        }
    }
    return ans;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    for(int i = 0; i < n; i++) {
        cin >> grid[i];
    }
    cout << solve() << "\n";
    return 0;
}
