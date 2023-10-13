#include <bits/stdc++.h>
using namespace std;

vector<bool> visited(1048576, false);
vector<string> grid (1024);
int n, m;
int ai[] = {1, 0, -1, 0};
int aj[] = {0, 1, 0, -1};

void bfs(int i, int j) {
    int i2, j2;
    pair<int, int> temp;
    queue<pair<int, int> > q;
    visited[i * m + j] = true;
    q.emplace(i, j);
    while(!q.empty()) {
        temp = q.front();
        q.pop();
        for(int k = 0; k < 4; k++) {
            i2 = temp.first + ai[k];
            j2 = temp.second + aj[k];
            if(i2 >= 0 && i2 < n && j2 >= 0 && j2 < m) {
                if(grid[i2][j2] == '.' && visited[i2 * m + j2] == false) {
                    q.emplace(i2, j2);
                    visited[i2 * m + j2] = true;
                }
            }
        }
    }
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int counter = 0;
    string line;
    cin >> n >> m;
    getline(cin, line);
    grid.reserve(n);
    for(int i = 0; i < n; i++) {
        getline(cin, line);
        grid[i] = line;
    }
    for(int j = 0; j < n; j++) {
        for(int k = 0; k < m; k++) {
            if(grid[j][k] == '.' && visited[j * m + k] == false) {
                bfs(j, k);
                counter++;
            }
        }
    }
    cout << counter << "\n";
    return 0;
}