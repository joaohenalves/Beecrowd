#include <bits/stdc++.h>
using namespace std;

#define MAX 212
#define MAXK 112

vector<vector<int>> graph(MAX);
int n, m, vis[MAX], vn[MAXK], vm[MAXK], match[MAX];

int aug(int u) {
    vis[u] = 1;
    for(int &v : graph[u]) {
        if(match[v] == -1 || (vis[match[v]] == 0 && aug(match[v]))) {
            match[v] = u;
            return 1;
        }
    }
    return 0;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t, i, j, c, ans;
    cin >> t;
    for(c = 1; c <= t; c++) {
        cin >> n;
        for(i = 0; i < n; i++) {
            cin >> vn[i];
        }
        cin >> m;
        for(i = 0; i < m; i++) {
            cin >> vm[i];
        }
        for(i = 0; i < m; i++) {
            for(j = 0; j < n; j++) {
                if((vn[j] != 0) && (vm[i] % vn[j] == 0)) {
                    graph[i].push_back(j + m);
                    graph[j + m].push_back(i);
                }
                if((vn[j] == 0) && (vm[i] == 0)) {
                    graph[i].push_back(j + m);
                    graph[j + m].push_back(i);
                }
            }
        }
        ans = 0;
        memset(match, -1, sizeof(match));
        for(i = 0; i < m; i++) {
            memset(vis, 0, sizeof(vis));
            if(vis[i] == 0) ans += aug(i);
        }
        cout << "Case " << c << ": " << ans << "\n";
        for(i = 0; i < n + m; i++) graph[i].clear();
    }
    return 0;
}
