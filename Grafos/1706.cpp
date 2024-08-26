#include <bits/stdc++.h>
using namespace std;

#define MAX 1123
#define MAXG 112
#define MOD 1000000007
#define INF 1123456789
#define EPS 1e-9
typedef long long ll;
typedef pair<int, int> ii;
 
int n, m, counter, vis[MAX], type[MAX];
vector<vector<int>> graph(MAX);

void dfs(int u) {
    vis[u] = 1;
    if(type[u] == 1) counter++;
    for(int v : graph[u]) {
        if(vis[v] == 0) {
            dfs(v);
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t, u, v, ans;
    char c;
    while(cin >> n >> m) {
        for(int i = 0; i < n; i++) {
            cin >> c;
            type[i] = !(c == 'A');
        }
        for(int i = 0; i < m; i++) {
            cin >> u >> v;
            u--; v--;
            graph[u].push_back(v);
            graph[v].push_back(u);
        }
        ans = 0;
        memset(vis, 0, sizeof(vis));
        for(int i = 0; i < n; i++) {
            if(vis[i] == 0) {
                counter = 0;
                dfs(i);
                if(counter & 1) ans = 1;
            }
        }
        cout << (ans ? 'N' : 'Y') << "\n";
        for(int i = 0; i < n; i++) graph[i].clear();
    }
    return 0;
}
