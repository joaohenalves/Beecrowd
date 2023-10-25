#include <bits/stdc++.h>
using namespace std;

#define INF 1e9
typedef unordered_map<int, int> umii;

vector<string> grid(112);
vector<int> marked(11234);
vector<int> dist(11234);
int si[] = {-1, 1, 0, 0};
int sj[] = {0, 0, 1, -1};
int finishDistances[11][11];
int n, p;

void bfs(int i, int j, int player, umii &teleportsIds) {
    fill(marked.begin(), marked.begin() + n * n, 0);
    fill(dist.begin(), dist.begin() + n * n, INF);
    queue<pair<int, int> > q;
    int ti, tj, ii, jj, found = 0;
    q.emplace(i, j);
    dist[i * n + j] = 0;
    marked[i * n + j] = 1;
    while(!q.empty()) {
        ti = q.front().first;
        tj = q.front().second;
        q.pop();
        if(grid[ti][tj] == 'X') {
            found++;
            finishDistances[player][teleportsIds[ti * n + tj]] = dist[ti * n + tj];
        }
        if(found == p) return;
        for(int k = 0; k < 4; k++) {
            ii = ti + si[k];
            jj = tj + sj[k];
            if(ii >= 0 && ii < n && jj >= 0 && jj < n && !marked[ii * n + jj] && grid[ii][jj] != '#') {
                q.emplace(ii, jj);
                dist[ii * n + jj] = dist[ti * n + tj] + 1;
                marked[ii * n + jj] = 1;
            }
        }
    }
}

int solve() {
    int current, minSol = INF;
    vector<int> perm(p);
    iota(perm.begin(), perm.end(), 0);
    do {
        current = 0;
        for(int i = 0; i < p; i++) {
            if(finishDistances[i][perm[i]] == INF) { current = 0; break; }
            current = max(current, finishDistances[i][perm[i]]);
        }
        if(current) minSol = min(current, minSol);
    } while(next_permutation(perm.begin(), perm.end()));
    return minSol;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t, id, ans;
    char c;
    cin >> t;
    while(t--) {
        cin >> n >> p;
        vector<pair<int, int> > playerPos;
        umii teleportsIds;
        id = 0;
        for(int i = 0; i < p; i++) {
            for(int j = 0; j < p; j++) {
                finishDistances[i][j] = INF;
            }
        }
        for(int i = 0; i < n; i++) {
            cin >> grid[i];
            for(int j = 0; j < n; j++) {
                if(grid[i][j] == 'G') playerPos.emplace_back(i, j);
                else if(grid[i][j] == 'X') teleportsIds[i * n + j] = id++;
            }
        }
        for(int i = 0; i < p; i++) {
            bfs(playerPos[i].first, playerPos[i].second, i, teleportsIds);
        }
        ans = solve();
        cout << (ans != INF ? ans : -1) << "\n";
    }
    return 0;
}
