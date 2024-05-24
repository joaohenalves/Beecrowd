#include <bits/stdc++.h>
using namespace std;

#define MAX 26

bool grid[MAX][MAX], marked[MAX][MAX];
int ai[] = {-1, 1, 0, 0}, aj[] = {0, 0, 1, -1};

void dfs(int i, int j) {
    int ii, jj;
    marked[i][j] = 1;
    for(int k = 0; k < 4; k++) {
        ii = ai[k] + i;
        jj = aj[k] + j;
        if(ii >= 0 && ii < 5 && jj >= 0 && jj < 5 && grid[ii][jj] == 0 && marked[ii][jj] == 0) {
            dfs(ii, jj);
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int i, j, t;
    cin >> t;
    while(t--) {
        for(i = 0; i < 5; i++) {
            for(j = 0; j < 5; j++) {
                cin >> grid[i][j];
            }
        }
        memset(marked, 0, sizeof(marked));
        dfs(0, 0);
        cout << (marked[4][4] ? "COPS" : "ROBBERS") << "\n";
    }
    return 0;
}
