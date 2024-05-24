#include <bits/stdc++.h>
using namespace std;

constexpr int INF = INT_MAX;

char grid[112][112], marked[112][112];
int n, p, current, minSol, aux, players[11][2], dist[112][112], finishDist[11][11], perm[11], chosen[11];
int ai[] = {-1, 1, 0, 0};
int aj[] = {0, 0, 1, -1};

void bfs(int si, int sj, int id) {
    int i, j, k, qi, qj, ii, jj;
    queue<pair<int, int> > q;
    for(i = 0; i < n; i++) {
        for(j = 0; j < n; j++) {
            marked[i][j] = 0;
            dist[i][j] = INF;
        }
    }
    for(i = 0; i < p; i++) finishDist[id][i] = INF;
    q.emplace(si, sj);
    dist[si][sj] = 0;
    marked[si][sj] = 1;
    while(!q.empty()) {
        auto [qi, qj] = q.front();
        q.pop();
        if(grid[qi][qj] >= '0' && grid[qi][qj] <= '9') {
            finishDist[id][grid[qi][qj] - 48] = dist[qi][qj];
        }
        for(k = 0; k < 4; k++) {
            ii = qi + ai[k];
            jj = qj + aj[k];
            if(ii >= 0 && ii < n && jj >= 0 && jj < n && !marked[ii][jj] && grid[ii][jj] != '#') {
                dist[ii][jj] = dist[qi][qj] + 1;
                marked[ii][jj] = 1;
                q.emplace(ii, jj);
            }
        }
    }
}

void search(int idx) {
    if (idx == p) {
        current = 0;
        for(int i = 0; i < p; i++) {
            current = max(current, finishDist[i][perm[i]]);
        }
        minSol = min(minSol, current);
    } else {
        for (int i = 0; i < p; i++) {
            if (chosen[i]) continue;
            chosen[i] = true;
            perm[idx] = i;
            aux = finishDist[idx][i];
            if(aux < minSol) search(idx + 1);
            chosen[i] = false;
        }
    }
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int i, j, t, ip, ix;
    cin >> t;
    while(t--) {
        cin >> n >> p;
        ip = ix = 0;
        for(i = 0; i < n; i++) {
            for(j = 0; j < n; j++) {
                cin >> grid[i][j];
                if(grid[i][j] == 'G') {
                    players[ip][0] = i;
                    players[ip][1] = j;
                    ip++;
                } else if(grid[i][j] == 'X') {
                    grid[i][j] = ix + 48;
                    ix++;
                }
            }
        }
        for(i = 0; i < p; i++) {
            bfs(players[i][0], players[i][1], i);
        }
        minSol = INF;
        memset(chosen, 0, sizeof(chosen));
        search(0);
        cout << (minSol != INF ? minSol : -1) << "\n";
    }
    return 0;
}
