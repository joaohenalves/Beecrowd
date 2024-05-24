#include <bits/stdc++.h>
using namespace std;

#define MAX 2123
#define pos(x) ((x) << 1)
#define neg(x) (pos(x) + 1)

vector<vector<int>> graph(MAX);
int n, consis, comp, vis[MAX];

void addEdge(int u, int v) {
    graph[u].push_back(v);
    graph[v].push_back(u);
}

int dfs(int u) {
    int ret = 0;
    if(vis[u]) return 0;
    vis[u] = comp;
    if(vis[u + ((u & 1) ? -1 : 1)] == vis[u]) consis = 0;
    for(int &v : graph[u]) {
        ret += dfs(v);
    }
    return ret + (!(u & 1));
}

int _dfs(int u) {
    if(vis[u]) return 0;
    comp++;
    return dfs(u);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int i, j, ans;
    char val[MAX];
    while(scanf("%d", &n), n) {
        ans = 0;
        consis = 1;
        comp = 0;
        for(i = 1; i <= n; i++) {
            scanf(" Sentence %d is %[a-z].", &j, val);
            if(val[0] == 't') {
                addEdge(pos(i), pos(j));
                addEdge(neg(i), neg(j));
            } else if(val[0] == 'f') {
                addEdge(pos(i), neg(j));
                addEdge(neg(i), pos(j));
            }
        }
        memset(vis, 0, sizeof(vis));
        for(i = 1; i <= n; i++) {
            ans += max(_dfs(pos(i)), _dfs(neg(i)));
        }
        if(consis) cout << ans;
        else cout << "Inconsistent";
        cout << "\n";
        for(i = 1; i <= neg(n); i++) graph[i].clear();
    }
    return 0;
}
