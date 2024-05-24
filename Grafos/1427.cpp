#include <bits/stdc++.h>
using namespace std;

#define INF 1e9
typedef pair<int, int> ii;

unordered_map<string, int> names;
char keys[112][25];
int dist[112][112];
int parent[112][112];
int n;

void floydWarshall() {
    int i, j, k;
    for(k = 0; k < n; k++) {
        for(i = 0; i < n; i++) {
            for(j = 0; j < n; j++) {
                if(dist[i][j] > dist[i][k] + dist[k][j] &&
                    dist[i][k] != INF && dist[k][j] != INF) {
                        dist[i][j] = dist[i][k] + dist[k][j];
                        parent[i][j] = parent[i][k];
                    }
            }
        }
    }
}

void pathRecovery(int u, int v) {
    vector<int> path = {u};
    while(u != v) {
        u = parent[u][v];
        path.push_back(u);
    }
    int s = path.size();
    cout << "Path:";
    for(int i = 0; i < s - 1; i++) {
        cout << keys[path[i]] << " ";
    }
    if(s == 1) cout << keys[path[s - 1]] << " ";
    cout << keys[path[s - 1]] << "\n";
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int c, i, j, cost, q, ans;
    char name[25];
    string u, v;
    cin >> c;
    while(c--) {
        cin >> n;
        for(i = 0; i < n; i++) {
            cin >> name;
            names[name] = i;
            strcpy(keys[i], name);
        }
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                cin >> cost;
                dist[i][j] = (cost != -1 ? cost : INF);
                parent[i][j] = (cost != -1 ? j : -1);
            }
        }
        floydWarshall();
        cin >> q;
        while(q--) {
            cin >> name >> u >> v;
            ans = dist[names[u]][names[v]];
            if(ans != INF) {
                cout << "Mr " << name << " to go from " << u << " to " << v
                    << ", you will receive " << ans << " euros\n";
                pathRecovery(names[u], names[v]);
            } else cout << "Sorry Mr " << name << " you can not go from " << u << " to " << v << "\n";
        }
        names.clear();
    }
    return 0;
}
