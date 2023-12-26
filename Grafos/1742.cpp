#include <bits/stdc++.h>
using namespace std;

constexpr int MOD = 1000000007;
constexpr int INF = INT_MAX;
typedef pair<int, int> pi;

int n, m, si, sj, ti, tj, dist[1123][1123][2];
bool res[1123][1123][4];
int ai[] = {-1, 1, 0, 0};
int aj[] = {0, 0, 1, -1};

int bfs() {
    queue<pi> q;
    int ii, jj, qi, qj, targetDist = INF;
    dist[si][sj][0] = 0;
    dist[si][sj][1] = 1;
    q.emplace(si, sj);
    while(!q.empty()) {
        auto [qi, qj] = q.front();
        q.pop();
        if(dist[qi][qj][0] > targetDist) return dist[ti][tj][1];
        for(int k = 0; k < 4; k++) {
            ii = qi + ai[k];
            jj = qj + aj[k];
            if(ii >= 0 && ii < n && jj >= 0 && jj < m && res[qi][qj][k] == false) {
                if(dist[ii][jj][0] > dist[qi][qj][0] + 1) {
                    dist[ii][jj][0] = dist[qi][qj][0] + 1;
                    dist[ii][jj][1] += dist[qi][qj][1];
                    dist[ii][jj][1] %= MOD;
                    q.emplace(ii, jj);
                } else if(dist[ii][jj][0] == dist[qi][qj][0] + 1) {
                    dist[ii][jj][1] += dist[qi][qj][1];
                    dist[ii][jj][1] %= MOD;
                } else continue;
                if(ii == ti && jj == tj) targetDist = dist[ti][tj][0];
            }
        }
    }
    return dist[ti][tj][1];
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int i, j, k, h, bx, by, tx, ty, q;
    while(cin >> m >> n >> h) {
        n++; m++;
        for(i = 0; i < n; i++) {
            for(j = 0; j < m; j++) {
                for(k = 0; k < 4; k++) res[i][j][k] = false;
            }
        }
        for(i = 0; i < h; i++) {
            cin >> bx >> by >> tx >> ty;
            for(j = bx + 1; j < tx; j++) res[ty][j][0] = true;
            for(j = bx + 1; j < tx; j++) res[by][j][1] = true;
            for(j = by + 1; j < ty; j++) res[j][bx][2] = true;
            for(j = by + 1; j < ty; j++) res[j][tx][3] = true;
        }
        cin >> q;
        while(q--) {
            cin >> sj >> si >> tj >> ti;
            for(i = 0; i < n; i++) {
                for(j = 0; j < m; j++) {
                    dist[i][j][0] = INF;
                    dist[i][j][1] = 0;
                }
            }
            cout << bfs() << "\n";
        }
        cout << "\n";
    }
    return 0;
}
