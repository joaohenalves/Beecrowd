#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef tuple<int, int, int> iii;

#define MAX 1123
#define INF 112345678

vector<iii> sensors;
int m, n, k, parent[MAX], nodeRank[MAX], edges[MAX][5];

int findSet(int u) {
    return parent[u] == u ? u : (parent[u] = findSet(parent[u]));
}

void unionSets(int u, int v) {
    u = findSet(u);
    v = findSet(v);
    if(nodeRank[u] < nodeRank[v]) parent[u] = v;
    else {
        parent[v] = u;
        if(nodeRank[u] == nodeRank[v]) nodeRank[u]++;
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int x1, y1, r1, x2, y2, r2, xa, ya, ra, s, flag = 1;
    cin >> m >> n >> k;
    for(int u = 0; u < k; u++) {
        parent[u] = u;
        nodeRank[u] = 0;
        edges[u][0] = edges[u][2] = 0;
        edges[u][1] = edges[u][3] = INF;
    }
    for(int i = 0; i < k; i++) {
        cin >> x1 >> y1 >> r1;
        sensors.emplace_back(x1, y1, r1);
        for(int j = 0; j < sensors.size() - 1; j++) {
            auto [x2, y2, r2] = sensors[j];
            xa = pow(x2 - x1, 2);
            ya = pow(y2 - y1, 2);
            ra = pow(r1 + r2, 2);
            if(xa + ya <= ra) {
                unionSets(i, j);
            }
        }
    }
    for(int i = 0; i < k; i++) {
        s = findSet(i);
        auto [x1, y1, r1] = sensors[i];
        edges[s][0] = max(edges[s][0], y1 + r1);
        edges[s][1] = min(edges[s][1], y1 - r1);
        edges[s][2] = max(edges[s][2], x1 + r1);
        edges[s][3] = min(edges[s][3], x1 - r1);
        if((edges[s][0] >= n && edges[s][1] <= 0) || (edges[s][2] >= m && edges[s][3] <= 0) ||
            (edges[s][1] <= 0 && edges[s][3] <= 0) || (edges[s][0] >= n && edges[s][2] >= m)) {
            flag = 0;
            break;
        }
    }
    cout << (flag ? "S" : "N") << "\n";
    return 0;
}
