#include <bits/stdc++.h>
using namespace std;

#define MAX 412
#define MAXG 112
#define MOD 1000000007
#define INF 1123456789
#define EPS 1e-9
typedef long long ll;
typedef pair<int, int> ii;
 
int n, m, timer, vis[MAX], tin[MAX], low[MAX], artic[MAX];
vector<vector<int>> graph(MAX);

void dfs(int u, int p) {
    vis[u] = 1;
    tin[u] = low[u] = timer++;
    for(int v : graph[u]) {
        if(v != p) {
            if(vis[v]) {
                low[u] = min(low[u], tin[v]);
            } else {
                dfs(v, u);
                low[u] = min(low[u], low[v]);
                if((p != -1 && low[v] >= tin[u]) ||
                    (p == -1 && low[v] > tin[u] && graph[u].size() > 1)) {
                    artic[u] = 1;
                }
            }
        }
    }
}

void findBridges() {
    timer = 0;
    memset(vis, 0, sizeof(vis));
    memset(tin, -1, sizeof(tin));
    memset(low, -1, sizeof(low));
    memset(artic, 0, sizeof(artic));
    for(int i = 0; i < n; i++) {
        if(vis[i] == 0) dfs(i, -1);
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int flag, u, v, c = 1;
    while(cin >> n >> m, n) {
        for(int i = 0; i < m; i++) {
            cin >> u >> v;
            u--; v--;
            graph[u].push_back(v);
            graph[v].push_back(u);
        }
        findBridges();
        flag = 0;
        cout << "Teste " << c << "\n";
        for(int i = 0; i < n; i++) {
            if(artic[i]) {
                cout << i + 1 << " ";
                flag = 1;
            }
        }
        cout << (flag ? "\n\n" : "nenhum\n\n");
        for(int i = 0; i < n; i++) graph[i].clear();
        c++;
    }
    return 0;
}
