#include <bits/stdc++.h>
using namespace std;

int ai[] = {-1, 1, 0, 0};
int aj[] = {0, 0, 1, -1};
bitset<11234> visited;
unordered_map<char, int> moves;
vector<string> grid(112);
int n, m;

bool solve() {
    if(grid[0][0] == '.') return false;
    int i = 0, j = 0, state;
    for(;;) {
        if(i < 0 || i >= n || j < 0 || j >= m) return false;
        if(visited[i * m + j]) return false;
        if(grid[i][j] == '*') return true;
        visited[i * m + j] = true;
        if(grid[i][j] != '.') state = moves[grid[i][j]];
        i += ai[state]; j += aj[state];
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    string temp;
    moves['^'] = 0;
    moves['v'] = 1;
    moves['>'] = 2;
    moves['<'] = 3;
    cin >> m >> n;
    for(int i = 0; i < n; i++) cin >> grid[i];
    cout << (solve() ? "*" : "!") << "\n";
    return 0;
}
