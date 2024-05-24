#include <bits/stdc++.h>
using namespace std;

bitset<2500> visited;
vector<string> grid;
int n, m;

int id[] = {-1, 1, 0, 0};
int jd[] = {0, 0, 1, -1};

void dfs(int i, int j) {
    int i1, j1;
    visited[i * m + j] = 1;
    grid[i][j] = 'T';
    for(int d = 0; d < 4; d++) {
        i1 = i + id[d];
        j1 = j + jd[d];
        if(i1 >= 0 && i1 < n && j1 >= 0 && j1 < m && grid[i1][j1] == 'A' && !visited[i1 * m + j1]) {
            dfs(i1, j1);
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    string temp;
    while(cin >> n >> m, n) {
        cin.ignore();
        grid.clear();
        visited.reset();
        for(int k = 0; k < n; k++) {
            getline(cin, temp);
            grid.push_back(temp);
        }
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(grid[i][j] == 'T' && visited[i * m + j] == 0) {
                    dfs(i, j);
                }
            }
        }
        for(int l = 0; l < n; l++) {
            cout << grid[l] << "\n";
        }
        cout << "\n";
    }
    return 0;
}
